#include <stdio.h>
#include "platform.h"
#include "xbasic_types.h"
#include "xiomodule.h"

#include "mmcm_params.h"

/**
 * Parameter section
 * In this section all variables are defined.
 */

// Index for parameter arrays m, d and o
volatile int series_index = 0;
int start_index= 0;
int stop_index = sizeof(m_values) / sizeof(m_values[0]);

// interval-value for time intervals. Default: Every
// 600 seconds the test circuit will be overclocked
volatile int interval = 10;


// two millisecond variables for interrupt service routine FIT2 to increment
// and for frequency_measurement
volatile int ms = 0;
volatile int m_ms = 0;

// second variable for FIT1
volatile int second = 0;

// variables for counting errors per second and
// all errors in this run
volatile int count_errors = 0;
volatile int count_errors_all = 0;

// uart/gpio variables
u32 uGpi1, uGpi2, uGpi3, uGpi4, uGpo1;
u32 uDevId = XPAR_IOMODULE_0_DEVICE_ID;

// software states
enum states {
	idle = 0,
	init = 3,
	end = 5,
};
enum states state = init;

// Input frequency of the second MMCM clock generator in kHz
// MMCM_INPUT_FREQ is specified in mmcm_params.h
int mmcm_input_freq = MMCM_INPUT_FREQ;


/**
 * MMCM Memory Pointers
 * Initialization of the pointers to the MMCM registers for parameters M, D and O
 */

// PHASEMUX [15:13] RESERVED [12] HIGH [11:6] LOW [5:0]
volatile unsigned short * pMMCMo1 = (volatile unsigned short *)(0xC0000000 + (0x08<<2));
// RESERVED [15:10] MX [9:8] EDGE [7] NO COUNT [6] DELAY TIME [5:0]
volatile unsigned short * pMMCMo2 = (volatile unsigned short *)(0xC0000000 + (0x09<<2));
// PHASEMUX [15:13] RESERVED [12] HIGH [11:6] LOW [5:0]
volatile unsigned short * pMMCMm1 = (volatile unsigned short *)(0xC0000000 + (0x14<<2));
// RESERVED [15:10] MX [9:8] EDGE [7] NO COUNT [6] DELAY TIME [5:0]
volatile unsigned short * pMMCMm2 = (volatile unsigned short *)(0xC0000000 + (0x15<<2));
// RESERVED [15:14] EDGE [13] NO COUNT [12] HIGH [11:6] LOW [5:0]
volatile unsigned short * pMMCMd1 = (volatile unsigned short *)(0xC0000000 + (0x16<<2));
//volatile unsigned short * pMMCMd2 = (volatile unsigned short *)(0xC0000000 + (0x17<<2));

XIOModule iomdle;

void countError();
void resetTestcircuit();
void resetCounter();
void cleanUp();
void initSystem();
void initFrequency();
void increaseFrequency();
void decreaseFrequency();
int setMultiplier(int m);
int setDividerOutput1(int o);
int setDivider(int d);
double calcFreq(int m, int d, int o);
void print(char *str);

// Interrupt Service Routines
void oneSecondInterruptRoutine( void* ip);
void oneMillisecondInterruptRoutine( void* ip);
void measureFrequencyInterruptRoutine( void* ip);
void errorObservationInterruptRoutine( void* ip);


// FIT1 Interrupt Service Routine
void oneSecondInterruptRoutine( void* ip) {
	second++;

	if(second % interval == 0) {
		XIOModule_Disable(&iomdle, 31); // Deactivate Error-Observation Interrupt
		increaseFrequency();
		XIOModule_Enable(&iomdle, 31); 	// Activate Error-Observation Interrupt
	}
	count_errors_all += count_errors;
	xil_printf("%d; %d; %d; %d; %d; %d; %d; %d; %d;\n\r", second, count_errors, count_errors_all, series_index, m_values[series_index], d_values[series_index], o_values[series_index], (mmcm_input_freq/(d_values[series_index]*o_values[series_index]))*m_values[series_index], 10000000000/m_ms);
	count_errors = 0;
}

// FIT2 Interrupt Service Routine
void oneMillisecondInterruptRoutine( void* ip ) {
	ms++; 								// increments the 10 ms variable
}

void measureFrequencyInterruptRoutine( void* ip) {
	m_ms = ms; 							// saves the ms value for calculating the frequency
	resetCounter(); 					// reset the counter..
	ms = 0;								// and set the ms value back to zero for a new calculation
}

void errorObservationInterruptRoutine( void* ip) {
	//XIOModule_Disable(&iomdle, 31);		// Deactivate Error-Observation Interrupt
	count_errors++;						// count error per second
	//count_errors_all++;					// count all errors occured in this run
	resetTestcircuit();					// reset the test circuit
	//XIOModule_Enable(&iomdle, 31);		// Activate Error-Observation Interrupt
}


int main() {


	/**
	 * Simple Statemachine for initialization, run and end
	 */

    while(1) {

    	switch(state) {
    		case init:
    			/**
    			 * State init is only of initialization all components
    			 * like GPIO, UART, etc.
    			 * After that the MMCM gets the first parameter set for the start
    			 * frequency.
    			 */
    			initSystem();
    			initFrequency();
    			resetCounter();
    			series_index = start_index;
    			state = idle;
    			break;
    		case idle:

    			/**
    			 * do nothing
    			 */

    			break;
    		case end:
    			/**
    			 * Clean up the system
    			 * see Xilinx XIL Kernel / Library for more information
    			 */
    			cleanUp();
    			return 0;
    			break;
    		default:
    			// default state
    			state = idle;
    			break;
		}

    }

    return 0;
}

// User Functions
void countError() {
	count_errors++;
	count_errors_all++;
}

void inline resetTestcircuit() {
	/**
	 * According to the GP Output Bitmap the reset bit
	 * for the test circuit is set
	 */
	XIOModule_DiscreteWrite(&iomdle, 1, 2);
	XIOModule_DiscreteWrite(&iomdle, 1, 0);
}

void inline resetCounter() {
	/**
	 * According to the GP Output Bitmap the reset bit
	 * for the counter is set
	 */
	XIOModule_DiscreteWrite(&iomdle, 1, 4);
	XIOModule_DiscreteWrite(&iomdle, 1, 0);
}

void cleanUp() {
	 cleanup_platform();
}

void initSystem() {
	init_platform();

	XIOModule_Initialize(&iomdle, uDevId);
	XIOModule_Start(&iomdle);

	// Initialize GP INPUTs
	uGpi1 = XIOModule_DiscreteRead(&iomdle, 1);
	uGpi2 = XIOModule_DiscreteRead(&iomdle, 2);
	uGpi3 = XIOModule_DiscreteRead(&iomdle, 3);
	uGpi4 = XIOModule_DiscreteRead(&iomdle, 4);

	XIOModule_DiscreteWrite(&iomdle, 1, 0); // write 0 to GPO1

	// Connect ISRs
	XIOModule_Connect(&iomdle, 7, oneSecondInterruptRoutine, NULL);
	XIOModule_Enable(&iomdle, 7);

	XIOModule_Connect(&iomdle, 8, oneMillisecondInterruptRoutine, NULL);
	XIOModule_Enable(&iomdle, 8);

	XIOModule_Connect(&iomdle, 30, measureFrequencyInterruptRoutine, NULL);
	XIOModule_Enable(&iomdle, 30); // BIT 14 (ext) Interrupt Controller

	XIOModule_Connect(&iomdle, 31, errorObservationInterruptRoutine, NULL);
	XIOModule_Disable(&iomdle, 31); // BIT 15 (ext) Interrupt Controller

	// Register and enable interrupts
	microblaze_register_handler(XIOModule_DeviceInterruptHandler, uDevId );
	microblaze_enable_interrupts();
}

void initFrequency() {
	/**
	 * Set initial MMCM parameters
	 * Resets MMCM and writes the values
	 */

	XIOModule_DiscreteWrite(&iomdle, 1, 2);

	setMultiplier(m_values[series_index]);
	setDivider(d_values[series_index]);
	setDividerOutput1(o_values[series_index]);

	XIOModule_DiscreteWrite(&iomdle, 1, 0);

	XIOModule_Enable(&iomdle, 31); // 15
}

void increaseFrequency() {
	/**
	 * checking if array pointer is not out of bounds
	 */
	series_index += 1;
	if( series_index >= sizeof(m_values) / sizeof(m_values[0]) || // dont' let the index run out of bounds
	    series_index > stop_index	) {
		series_index = start_index;
	}

	/**
	 * Reset for MMCM
	 * Write in MMCM
	 */
	XIOModule_DiscreteWrite(&iomdle, 1, 2);

	setMultiplier(m_values[series_index]);
	setDivider(d_values[series_index]);
	setDividerOutput1(o_values[series_index]);

	XIOModule_DiscreteWrite(&iomdle, 1, 0);

	/**
	 * Counting second now starts at 0
	 */

	second = 0;
}

void decreaseFrequency() {
	/**
	 * Analogues to increaseFrequency()
	 */

	/**
	 * checking if array pointer is still not out of bounds
	 */
	series_index -= 1;
	if( series_index == 0 ||
	    series_index == start_index) {
		series_index = stop_index;
	}

	/**
	 * Reset MMCM
	 * Write in MMCM
	 */

	XIOModule_DiscreteWrite(&iomdle, 1, 2);

	setMultiplier(m_values[series_index]);
	setDivider(d_values[series_index]);
	setDividerOutput1(o_values[series_index]);

	XIOModule_DiscreteWrite(&iomdle, 1, 0);

	second = 0;
}

// obsolete, only for testing
void setValue(int high, int low, short *mptr) {
	*mptr = (1 << 12) + (high << 6) + low;
}

int setDivider(int m) {
	// RESERVED [15:14] EDGE [13] NO COUNT [12] HIGH [11:6] LOW [5:0]

	// gets the current value of the register
	unsigned short tempM1 = *pMMCMd1;
	unsigned short MASK;

	int ret = 0;


	if(m == 1) {
		//*pMMCMm2 = (1 << 6);
		MASK = 0xEFFF;
		tempM1 &= MASK;
		tempM1 |= (1<<12);
		*pMMCMd1 = tempM1;
		ret = 1;
	}
	if(m % 2 == 0) {

		MASK = 0xC000;
		tempM1 &= MASK;
		tempM1 |= ((m/2) <<6) + (m/2) + (0<<13) + (0<<12);
		*pMMCMd1 = tempM1;
		ret = 2;
	}
	if(m % 2 == 1 && m != 1) {
		MASK = 0xC000;
		tempM1 &= MASK;
		tempM1 |= ((m/2) <<6) + (m/2)+1 + (1<<13) + (0<<12);
		*pMMCMd1 = tempM1;
		ret = 3;
	}

	// memory barrier for writing values to MMCM
	mbar(1);
	mbar(2);

	return ret;
}

int setMultiplier(int m) {
	// PHASEMUX [15:13] RESERVED [12] HIGH [11:6] LOW [5:0]
	// RESERVED [15:10] MX [9:8] EDGE [7] NO COUNT [6] DELAY TIME [5:0]

	unsigned short tempM1 = *pMMCMm1;
	unsigned short tempM2 = *pMMCMm2;
	unsigned short MASK;

	int ret = 0;

	if(m == 1) {
		MASK = 0xF000;
		tempM1 &= MASK;
		*pMMCMm1 = tempM1;

		mbar(1);
		mbar(2);

		MASK = 0xFF3F;
		tempM2 &= MASK;
		tempM2 |= (0<<7) + (1<<6);
		*pMMCMm2 = tempM2;
		ret = 1;
	}
	if(m % 2 == 0) {
		MASK = 0xF000;
		tempM1 &= MASK;
		tempM1 |= ((m/2) <<6) + (m/2);
		*pMMCMm1 = tempM1;

		mbar(1);
		mbar(2);

		MASK = 0xFF3F;
		tempM2 &= MASK;
		tempM2 |= (0<<6) + (0<<7);
		*pMMCMm2 = tempM2;
		ret = 2;
	}
	if(m % 2 == 1 && m != 1) {
		MASK = 0xF000;
		tempM1 &= MASK;
		tempM1 |= ((m/2) <<6) + (m/2)+1;
		*pMMCMm1 = tempM1;

		mbar(1);
		mbar(2);

		MASK = 0xFF3F;
		tempM2 &= MASK;
		tempM2 |= (0<<6) + (1<<7);
		*pMMCMm2 = tempM2;
		ret = 3;
	}
	mbar(1);
	mbar(2);

	//xil_printf("[m, (r1-%d r2-%d)], ", tempM1, tempM2);

	return ret;
}

int setDividerOutput1(int m) {
	// PHASEMUX [15:13] RESERVED [12] HIGH [11:6] LOW [5:0]
	// RESERVED [15:10] MX [9:8] EDGE [7] NO COUNT [6] DELAY TIME [5:0]

	unsigned short tempM1 = *pMMCMo1;
	unsigned short tempM2 = *pMMCMo2;
	unsigned short MASK;

	int ret = 0;

	if(m == 1) {
		MASK = 0xF000;
		tempM1 &= MASK;
		*pMMCMo1 = tempM1;

		mbar(1);
		mbar(2);

		MASK = 0xFF3F;
		tempM2 &= MASK;
		tempM2 |= (0<<7) + (1<<6);
		*pMMCMo2 = tempM2;
		ret = 1;
	}
	if(m % 2 == 0) {

		MASK = 0xF000;
		tempM1 &= MASK;
		tempM1 |= ((m/2) <<6) + (m/2);
		*pMMCMo1 = tempM1;

		mbar(1);
		mbar(2);

		MASK = 0xFF3F;
		tempM2 &= MASK;
		tempM2 |= (0<<6) + (0<<7);
		*pMMCMo2 = tempM2;
		ret = 2;
	}
	if(m % 2 == 1 && m != 1) {
		MASK = 0xF000;
		tempM1 &= MASK;
		tempM1 |= ((m/2) <<6) + (m/2)+1;
		*pMMCMo1 = tempM1;

		mbar(1);
		mbar(2);

		MASK = 0xFF3F;
		tempM2 &= MASK;
		tempM2 |= (0<<6) + (1<<7);
		*pMMCMo2 = tempM2;
		ret = 3;
	}
	mbar(1);
	mbar(2);


	return ret;
}

double calcFreq(int m, int d, int o) {
	double nenner = d*o;
	return (double)(100 * m) / ((double)nenner);
}
