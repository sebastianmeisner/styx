/*
 * mmcm_params.h
 *
 *  Created on: 10.06.2014
 *      Author: meise
 */

#ifndef MMCM_PARAMS_H_
#define MMCM_PARAMS_H_


 #define MMCM_INPUT_FREQ 650000
//#define MMCM_INPUT_FREQ 700000

/**
 * Array section
 * The following arrays contains alle parameters ever tried for this bachelor thesis
 * The commented lines are special values which were used for some tests
 * The not commented lines are the last used array values for MMCM parameters M, D and O
 */

#if MMCM_INPUT_FREQ == 650000
// 0.5540540540540541 to 0.6145833333333334, 143 different frequencies
// 650.0 MHz Base: 360.13513513513516 MHz to 399.4791666666667 MHz Range
volatile int m_values[] = {41,51,61,5,59,49,39,29,48,62,19,52,47,28,37,46,55,32,59,9,49,62,53,22,35,61,26,56,43,60,17,59,42,46,25,29,33,41,49,53,57,8,63,55,47,43,39,31,54,50,23,61,19,53,64,15,26,37,59,22,51,40,29,47,36,61,43,50,57,64,7,62,55,48,41,58,34,61,44,27,37,47,20,53,33,23,59,62,13,55,58,45,16,51,19,41,63,44,25,56,59,31,34,37,43,49,52,55,61,6,59,56,53,47,41,38,35,64,29,52,49,23,63,20,57,17,31,45,28,53,39,64,50,61,11,60,49,38,46,27,35,43,59};
volatile int d_values[] = {37,46,55,3,53,44,35,26,43,37,17,31,28,25,22,41,49,19,35,8,29,55,47,13,31,36,23,33,38,53,10,52,37,27,22,17,29,24,43,31,50,7,55,32,41,25,34,18,47,29,20,53,11,46,37,13,15,32,34,19,44,23,25,27,31,35,37,43,49,55,4,53,47,41,35,33,29,52,25,23,21,40,17,30,28,13,50,35,11,31,49,38,9,43,16,23,53,37,14,47,33,26,19,31,24,41,29,46,34,5,49,31,44,26,34,21,29,53,16,43,27,19,52,11,47,14,17,37,23,29,32,35,41,50,6,49,40,31,25,22,19,35,32};
volatile int o_values[] = {2,2,2,3,2,2,2,2,2,3,2,3,3,2,3,2,2,3,3,2,3,2,2,3,2,3,2,3,2,2,3,2,2,3,2,3,2,3,2,3,2,2,2,3,2,3,2,3,2,3,2,2,3,2,3,2,3,2,3,2,2,3,2,3,2,3,2,2,2,2,3,2,2,2,2,3,2,2,3,2,3,2,2,3,2,3,2,3,2,3,2,2,3,2,2,3,2,2,3,2,3,2,3,2,3,2,3,2,3,2,2,3,2,3,2,3,2,2,3,2,3,2,2,3,2,2,3,2,2,3,2,3,2,2,3,2,2,2,3,2,3,2,3};

#elif MMCM_INPUT_FREQ == 700000
// 0.5147058823529411 to 0.57, 153 different frequencies
// 700.0 MHz Base: 360.2941176470588 MHz to 398.99999999999994 MHz Range
volatile int m_values[] = {35,17,33,32,63,31,61,30,59,29,57,14,55,27,53,26,64,51,25,49,61,24,47,58,23,45,11,43,64,21,52,62,41,61,20,59,49,39,58,19,56,37,46,55,18,62,53,35,52,43,17,59,50,33,49,8,63,47,31,46,61,53,15,37,59,44,29,43,50,57,14,55,41,34,27,47,40,53,13,64,51,38,63,44,25,31,37,49,61,12,59,47,41,35,64,58,23,57,34,45,28,61,11,38,54,43,32,53,58,21,52,31,41,51,61,5,59,49,39,29,48,62,19,52,47,28,37,46,55,32,59,9,49,62,53,22,35,61,26,56,43,60,17,59,42,46,25,29,33,41,49,53,57};
volatile int d_values[] = {34,11,32,31,61,20,59,29,38,28,55,9,53,26,34,25,41,49,16,47,39,23,30,37,22,43,7,41,61,20,33,59,26,58,19,56,31,37,55,12,53,35,29,52,17,39,50,22,49,27,16,37,47,31,46,5,59,44,29,43,38,33,14,23,55,41,18,40,31,53,13,34,38,21,25,29,37,49,8,59,47,35,58,27,23,19,34,30,56,11,36,43,25,32,39,53,14,52,31,41,17,37,10,23,49,26,29,32,35,19,47,28,37,46,55,3,53,44,35,26,43,37,17,31,28,25,22,41,49,19,35,8,29,55,47,13,31,36,23,33,38,53,10,52,37,27,22,17,29,24,43,31,50};
volatile int o_values[] = {2,3,2,2,2,3,2,2,3,2,2,3,2,2,3,2,3,2,3,2,3,2,3,3,2,2,3,2,2,2,3,2,3,2,2,2,3,2,2,3,2,2,3,2,2,3,2,3,2,3,2,3,2,2,2,3,2,2,2,2,3,3,2,3,2,2,3,2,3,2,2,3,2,3,2,3,2,2,3,2,2,2,2,3,2,3,2,3,2,2,3,2,3,2,3,2,3,2,2,2,3,3,2,3,2,3,2,3,3,2,2,2,2,2,2,3,2,2,2,2,2,3,2,3,3,2,3,2,2,3,3,2,3,2,2,3,2,3,2,3,2,2,3,2,2,3,2,3,2,3,2,3,2};

#endif


// ##########################################################################################
// !!! DON'T USE THE FOLLOWING PARAMETERS: THEY ARE NOT VALID ACCORDING TO THE "Virtex-6 FPGA
// !!! Clocking Resources User Guide"
// ##########################################################################################


// 1.2 to ~1.326, 106 different frequencies
// 350MHz Base: 420MHz to 464.088 MHz Range
// 300MHz Base: 360MHz to 397.826 MHz Range
//volatile int m_values[] = {6,59,53,47,41,35,64,29,52,23,63,40,57,17,62,45,28,39,50,61,11,60,49,38,27,43,59,16,53,37,58,21,47,26,57,31,36,41,46,51,56,61,5,64,59,54,49,44,39,34,63,29,53,24,43,62,19,52,33,47,61,14,51,37,60,23,55,32,41,50,59,9,58,49,40,31,53,22,57,35,48,61,13,56,43,30,47,64,17,55,38,59,21,46,25,54,29,62,33,37,41,45,49,53,57,61};
//volatile int d_values[] = {5,49,44,39,34,29,53,24,43,19,52,33,47,14,51,37,23,32,41,50,9,49,40,31,22,35,48,13,43,30,47,17,38,21,46,25,29,33,37,41,45,49,4,51,47,43,39,35,31,27,50,23,42,19,34,49,15,41,26,37,48,11,40,29,47,18,43,25,32,39,46,7,45,38,31,24,41,17,44,27,37,47,10,43,33,23,36,49,13,42,29,45,16,35,19,41,22,47,25,28,31,34,37,40,43,46};
//volatile int o_values[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

// ~1.02857 to 1.14, 127 different frequencies
// 350MHz Base: 360MHz to 399 MHz Range
// 300MHz Base: 308.571MHz to 342MHz Range
//volatile int m_values[] = {36,35,34,33,32,63,31,61,30,59,29,57,28,55,27,53,26,51,25,49,24,47,23,45,22,43,64,21,62,41,61,20,59,39,58,19,56,37,55,18,53,35,52,17,50,33,49,16,63,47,31,46,61,15,59,44,29,43,57,14,55,41,27,40,53,13,64,51,38,63,25,62,37,49,61,12,59,47,35,58,23,57,34,45,56,11,54,43,32,53,21,52,31,41,51,61,10,59,49,39,29,48,19,47,28,37,46,55,64,9,62,53,44,35,61,26,43,60,17,59,42,25,58,33,41,49,57};
//volatile int d_values[] = {35,34,33,32,31,61,30,59,29,57,28,55,27,53,26,51,25,49,24,47,23,45,22,43,21,41,61,20,59,39,58,19,56,37,55,18,53,35,52,17,50,33,49,16,47,31,46,15,59,44,29,43,57,14,55,41,27,40,53,13,51,38,25,37,49,12,59,47,35,58,23,57,34,45,56,11,54,43,32,53,21,52,31,41,51,10,49,39,29,48,19,47,28,37,46,55,9,53,44,35,26,43,17,42,25,33,41,49,57,8,55,47,39,31,54,23,38,53,15,52,37,22,51,29,36,43,50};
//volatile int o_values[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};


// ~1.17949, ~1.17857, ~1.02857  to ~1.1395, ~0.9661, 129 different frequencies
// 350MHz Base: 412.820 MHz, 412.500 MHz, 360 MHz to 398.811 MHz, 338.124 MHz
// 300MHz Base: 353.846 MHz, 353.571 MHz, 308.571 MHz to 342.860 MHz, 289.830 MHz
//volatile int m_values[] = {46,33,36,35,34,33,32,63,31,61,30,59,29,57,28,55,27,53,26,51,25,49,24,47,23,45,22,43,64,21,62,41,61,20,59,39,58,19,56,37,55,18,53,35,52,17,50,33,49,16,63,47,31,46,61,15,59,44,29,43,57,14,55,41,27,40,53,13,64,51,38,63,25,62,37,49,61,12,59,47,35,58,23,57,34,45,56,11,54,43,32,53,21,52,31,41,51,61,10,59,49,39,29,48,19,47,28,37,46,55,64,9,62,53,44,35,61,26,43,60,17,59,42,25,58,33,41,49,57};
//volatile int d_values[] = {39,28,35,34,33,32,31,61,30,59,29,57,28,55,27,53,26,51,25,49,24,47,23,24,22,43,21,41,61,20,59,39,58,19,56,37,55,18,53,35,52,17,50,33,49,16,47,31,46,15,59,44,29,43,57,14,55,41,27,40,53,13,51,38,25,37,49,12,59,47,35,58,23,57,34,45,56,11,54,43,32,53,21,52,31,41,51,5,49,39,29,48,19,47,28,37,46,55,9,53,44,35,26,43,17,42,25,33,41,49,57,8,55,47,39,31,54,23,38,53,15,52,37,22,51,29,36,43,59};
//volatile int o_values[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

// ~1.04348 to 1.14, 107 frequencies
// 350MHz Base: 365.184 MHz to 399 MHz
// 300MHz Base: 313.043 MHz to 342 MHz
//volatile int m_values[] = {48,47,46,45,44,43,64,63,62,41,61,60,59,39,58,57,56,37,55,54,53,35,52,51,50,33,49,64,63,47,62,46,61,60,59,44,58,43,57,56,55,41,54,40,53,52,64,51,38,63,25,62,37,49,61,12,59,47,35,58,23,57,34,45,56,11,54,43,32,53,21,52,31,41,51,61,10,59,49,39,29,48,19,47,28,37,46,55,64,9,62,53,44,35,61,26,43,60,17,59,42,25,58,33,41,49,57};
//volatile int d_values[] = {46,45,44,43,42,41,61,60,59,39,58,57,56,37,55,54,53,35,52,51,50,33,49,48,47,31,46,60,59,44,58,43,57,56,55,41,54,40,53,52,51,38,50,37,49,48,59,47,35,58,23,57,34,45,56,11,54,43,32,53,21,52,31,41,51,10,49,39,29,48,19,47,28,37,46,55,9,53,44,35,26,43,17,42,25,33,41,49,57,8,55,47,39,31,54,23,38,53,15,52,37,22,51,29,36,43,50};
//volatile int o_values[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

// ~1.04348 to ~1.0851, 48 frequencies
// 350MHz Base: 365.184 MHz to 379.746 MHz
// 300MHz Base: 313.043 MHz to 325.531 MHz
//volatile int m_values[] = {48,47,46,45,44,43,64,63,62,41,61,60,59,39,58,57,56,37,55,54,53,35,52,51,50,33,49,64,63,47,62,46,61,60,59,44,58,43,57,56,55,41,54,40,53,52,64,51};
//volatile int d_values[] = {46,45,44,43,42,41,61,60,59,39,58,57,56,37,55,54,53,35,52,51,50,33,49,48,47,31,46,60,59,44,58,43,57,56,55,41,54,40,53,52,51,38,50,37,49,48,59,47};
//volatile int o_values[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

// ~1.07895, ~1.06667 to ~1.071429, 8 frequencies
// 350MHz Base: 377.610 MHz, 373.312 MHz to 375.000 MHz
// 300MHz Base: 323.684 MHz, 320.000 MHz to 321.428 MHz
//volatile int m_values[] = {41,32,63,47,31,46,61,60};
//volatile int d_values[] = {38,30,59,44,29,43,57,56};
//volatile int o_values[] = {1,1,1,1,1,1,1,1};

// 1.15 to ~1.18421, 37 frequencies
// 350MHz Base: 402.500 MHz to 414.450 MHz
// 300MHz Base: 345.000 MHz to 355.263 MHz
//volatile int m_values[] = {46,61,38,53,60,52,37,59,44,51,58,36,43,50,57,64,63,62,55,48,41,34,61,61,27,54,54,47,47,60,53,33,46,59,52,58,45};
//volatile int d_values[] = {40,53,33,46,52,45,32,51,38,44,50,31,37,43,49,55,54,53,47,41,35,29,52,52,23,46,46,40,40,51,45,28,39,50,44,49,38};
//volatile int o_values[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

// ~1.18367 to ~1.32609, 120 frequencies
// 350MHz Base: 414.236 MHz to 464.088 MHz
// 300MHz Base: 355.102 MHz to 397.826 MHz
//volatile int m_values[] = {58,45,64,51,57,63,44,50,62,37,43,49,55,61,12,59,53,47,41,35,64,29,52,23,63,40,57,17,62,45,28,39,50,61,11,60,49,38,27,43,59,16,53,37,58,21,47,26,57,31,36,41,46,51,56,61,5,64,59,54,49,44,39,34,63,29,53,24,43,62,19,52,33,47,61,14,51,37,60,23,55,32,41,50,59,9,58,49,40,31,53,22,57,35,48,61,13,56,43,30,47,64,17,55,38,59,21,46,25,54,29,62,33,37,41,45,49,53,57,61};
//volatile int d_values[] = {49,38,54,43,48,53,37,42,52,31,36,41,46,51,10,49,22,13,17,29,53,8,43,19,26,11,47,7,17,37,23,32,41,50,9,49,40,31,22,35,48,13,43,30,47,17,19,21,46,25,29,33,37,41,45,49,4,51,47,43,39,35,31,27,50,23,42,19,34,49,15,41,26,37,48,11,40,29,47,18,43,25,32,39,46,7,45,38,31,24,41,17,44,27,37,47,10,43,33,23,36,49,13,42,29,45,32,35,19,41,22,47,25,28,31,34,37,40,43,46};
//volatile int o_values[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,3,2,1,1,3,1,1,2,3,1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

// ~3.77778 to  3.9375 , 18 frequencies
// !!! 350MHz Base: 1322.192 MHz to 1378.125 MHz
// !!! 300MHz Base: 1133.333 MHz to 1181.250 MHz
//volatile int m_values[] = {34,53,38,61,42,46,50,54,58,62,35,39,43,47,51,55,59,63};
//volatile int d_values[] = {9,14,10,16,11,12,13,14,15,16,9,10,11,12,13,14,15,16};
//volatile int o_values[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

// 2.0 to 6.4, , 45 frequencies
// !!! 350MHz Base: 700.000 MHz to 2240.000 MHz
// !!! 300MHz Base: 600.000 MHz to 1920.000 MHz
//volatile int m_values[] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64};
//volatile int d_values[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
//volatile int o_values[] = {1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1 };

// ~1.512195 to ~2.8947, 404 frequencies
// !!! 350MHz Base: 529.232 MHz to 1013.155 MHz
// !!! 300MHz Base: 453.658 MHz to  868.421 MHz
//volatile int m_values[] = {62,59,56,53,50,47,44,41,38,35,64,61,58,55,52,49,23,43,63,60,57,37,54,17,48,31,45,59,14,53,39,64,25,61,36,47,58,11,63,52,41,30,49,19,46,27,62,35,43,51,59,8,61,53,45,37,29,50,21,55,34,47,60,13,57,44,31,49,18,59,41,64,23,51,28,61,33,38,43,48,53,58,63,5,62,57,52,47,42,37,32,59,27,49,22,61,39,56,17,63,46,29,41,53,12,55,43,31,50,19,64,45,26,59,33,40,47,54,61,7,58,51,44,37,30,53,23,62,39,55,16,57,41,25,59,34,43,52,61,9,56,47,38,29,49,20,51,31,42,53,64,11,57,46,35,59,24,61,37,50,63,13,54,41,28,43,58,15,62,47,32,49,17,53,36,55,19,59,40,61,21,44,23,48,25,52,27,56,29,60,31,64,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,63,60,63,61,59,57,55,53,51,49,47,45,43,41,39,37,35,33,64,31,60,29,56,27,52,25,48,23,44,21,61,40,59,19,55,36,53,17,49,32,47,62,15,58,43,28,41,54,13,63,50,37,61,24,59,35,46,57,11,64,53,42,31,51,20,49,29,38,47,56,9,61,52,43,34,59,25,41,57,16,55,39,62,23,53,30,37,44,51,58,7,61,54,47,40,33,59,26,45,64,19,50,31,43,55,12,53,41,29,46,63,17,56,39,61,22,49,27,59,32,37,42,47,52,57,62,5,63,58,53,48,43,38,33,61,28,51,23,64,41,59,18,49,31,44,57,13,60,47,34,55,21,50,29,37,45,53,61,8,59,51,43,35,62,27,46,19,49,30,41,52,63,11,58,47,36,61,25,64,39,53,14,59,45,31,48,17,54,37,57,20,63,43,23,49,26,55};
//volatile int d_values[] = {41,39,37,35,33,31,29,27,25,23,42,40,38,36,34,32,15,28,41,39,37,24,35,11,31,4,29,19,3,17,5,41,4,13,23,5,37,1,8,11,13,19,31,2,29,17,13,11,9,8,37,1,19,11,4,23,3,31,13,17,3,29,37,2,5,9,19,5,11,6,5,13,2,31,17,37,4,23,13,29,8,5,19,1,37,17,31,4,5,11,19,5,4,29,13,6,23,11,2,37,9,17,4,31,7,8,5,3,29,11,37,13,3,17,19,23,9,31,7,1,11,29,5,7,17,5,13,7,11,31,3,8,23,7,11,19,4,29,17,1,31,13,7,4,9,11,7,17,23,29,7,1,31,5,19,8,13,11,4,9,17,7,29,11,3,23,31,2,11,5,17,13,3,7,19,29,2,31,7,8,11,23,2,5,13,9,7,29,3,31,4,11,17,3,19,4,7,11,23,24,25,26,27,28,29,30,31,32,30,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,31,15,29,7,9,13,5,3,23,11,7,2,29,19,7,3,13,17,5,2,23,3,11,29,7,9,4,13,19,5,2,29,23,17,7,11,9,4,7,13,1,29,6,19,7,23,3,11,13,17,7,5,1,9,23,19,3,13,11,6,5,7,6,17,9,2,23,13,4,19,11,5,1,13,23,4,17,7,5,11,19,9,2,7,13,6,23,5,11,17,3,19,13,7,23,4,25,3,5,11,6,13,5,17,19,7,23,25,1,25,23,7,19,17,5,13,6,11,5,3,25,4,23,7,19,3,17,11,5,23,6,13,7,2,19,11,7,17,5,23,1,11,19,4,13,23,5,17,7,6,11,5,19,23,1,7,17,13,11,3,23,7,19,5,7,4,11,17,2,19,13,5,7,11,5,2,17,3,19};
//volatile int o_values[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,2,3,2,5,1,4,3,1,6,1,7,5,3,2,1,1,6,1,1,3,2,3,4,1,5,2,3,7,1,6,1,1,2,7,1,1,4,7,3,1,6,1,6,5,3,7,1,1,1,5,1,2,1,4,7,2,3,1,2,1,7,5,2,1,7,4,1,1,6,1,3,5,1,3,1,6,1,1,4,5,6,1,1,1,2,5,2,1,1,3,1,5,4,3,1,5,3,1,6,1,5,2,1,3,4,1,2,3,1,6,1,2,5,1,2,3,4,3,1,4,1,1,1,5,6,1,5,1,4,1,3,5,3,2,1,1,2,5,1,1,4,3,5,1,2,3,4,1,1,5,1,3,4,1,1,6,5,1,3,2,1,5,1,4,3,1,6,1,5,3,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,3,1,5,4,1,1,3,5,1,1,4,3,2,1,5,4,1,5,2,1,1,3,5,1,1,5,3,1,1,1,4,1,3,4,3,2,5,1,4,1,2,1,3,2,1,1,3,5,4,3,1,1,5,2,1,3,5,1,4,1,3,5,1,1,4,1,2,5,3,2,1,5,1,2,5,1,1,3,4,3,1,3,1,1,2,1,4,1,2,1,1,4,1,3,4,1,4,1,3,1,1,3,1,1,2,1,1,3,1,1,3,1,4,1,4,3,1,4,1,1,1,4,1,2,1,1,3,1,3,4,1,1,2,1,4,1,3,2,1,4,1,1,2,1,1,3,1,3,1,1,4,3,1,1,2,3,1,2,1,1,3,4,1,1,3,1,1,4,1,2,3,4,1,3,1};

// ~1.512195 to ~2.8947, 404 frequencies
// !!! 350MHz Base: 529.232 MHz to 1013.155 MHz
// !!! 300MHz Base: 453.658 MHz to  868.421 MHz
//volatile int m_values[] = {62,59,56,53,50,47,44,41,38,35,64,61,58,55,52,49,23,43,63,60,57,37,54,17,48,31,45,59,14,53,39,64,25,61,36,47,58,11,63,52,41,30,49,19,46,27,62,35,43,51,59,8,61,53,45,37,29,50,21,55,34,47,60,13,57,44,31,49,18,59,41,64,23,51,28,61,33,38,43,48,53,58,63,5,62,57,52,47,42,37,32,59,27,49,22,61,39,56,17,63,46,29,41,53,12,55,43,31,50,19,64,45,26,59,33,40,47,54,61,7,58,51,44,37,30,53,23,62,39,55,16,57,41,25,59,34,43,52,61,9,56,47,38,29,49,20,51,31,42,53,64,11,57,46,35,59,24,61,37,50,63,13,54,41,28,43,58,15,62,47,32,49,17,53,36,55,19,59,40,61,21,44,23,48,25,52,27,56,29,60,31,64,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,63,2,63,61,59,57,55,53,51,49,47,45,43,41,39,37,35,33,64,31,60,29,56,27,52,25,48,23,44,21,61,40,59,19,55,36,53,17,49,32,47,62,15,58,43,28,41,54,13,63,50,37,61,24,59,35,46,57,11,64,53,42,31,51,20,49,29,38,47,56,9,61,52,43,34,59,25,41,57,16,55,39,62,23,53,30,37,44,51,58,7,61,54,47,40,33,59,26,45,64,19,50,31,43,55,12,53,41,29,46,63,17,56,39,61,22,49,27,59,32,37,42,47,52,57,62,5,63,58,53,48,43,38,33,61,28,51,23,64,41,59,18,49,31,44,57,13,60,47,34,55,21,50,29,37,45,53,61,8,59,51,43,35,62,27,46,19,49,30,41,52,63,11,58,47,36,61,25,64,39,53,14,59,45,31,48,17,54,37,57,20,63,43,23,49,26,55};
//volatile int d_values[] = {41,39,37,35,33,31,29,27,25,23,42,40,38,36,34,32,15,28,41,39,37,24,35,11,31,4,29,19,3,17,5,41,4,13,23,5,37,1,8,11,13,19,31,2,29,17,13,11,9,8,37,1,19,11,4,23,3,31,13,17,3,29,37,2,5,9,19,5,11,6,5,13,2,31,17,37,4,23,13,29,8,5,19,1,37,17,31,4,5,11,19,5,4,29,13,6,23,11,2,37,9,17,4,31,7,8,5,3,29,11,37,13,3,17,19,23,9,31,7,1,11,29,5,7,17,5,13,7,11,31,3,8,23,7,11,19,4,29,17,1,31,13,7,4,9,11,7,17,23,29,7,1,31,5,19,8,13,11,4,9,17,7,29,11,3,23,31,2,11,5,17,13,3,7,19,29,2,31,7,8,11,23,2,5,13,9,7,29,3,31,4,11,17,3,19,4,7,11,23,4,5,13,9,7,29,5,31,8,1,31,6,29,7,9,13,5,6,23,11,7,4,19,6,17,4,31,3,29,7,9,13,5,3,23,11,7,2,29,19,7,3,13,17,5,2,23,3,11,29,7,9,4,13,19,5,2,29,23,17,7,11,9,4,7,13,1,29,6,19,7,23,3,11,13,17,7,5,1,9,23,19,3,13,11,6,5,7,6,17,9,2,23,13,4,19,11,5,1,13,23,4,17,7,5,11,19,9,2,7,13,6,23,5,11,17,3,19,13,7,23,4,25,3,5,11,6,13,5,17,19,7,23,25,1,25,23,7,19,17,5,13,6,11,5,3,25,4,23,7,19,3,17,11,5,23,6,13,7,2,19,11,7,17,5,23,1,11,19,4,13,23,5,17,7,6,11,5,19,23,1,7,17,13,11,3,23,7,19,5,7,4,11,17,2,19,13,5,7,11,5,2,17,3,19};
//volatile int o_values[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,2,3,2,5,1,4,3,1,6,1,7,5,3,2,1,1,6,1,1,3,2,3,4,1,5,2,3,7,1,6,1,1,2,7,1,1,4,7,3,1,6,1,6,5,3,7,1,1,1,5,1,2,1,4,7,2,3,1,2,1,7,5,2,1,7,4,1,1,6,1,3,5,1,3,1,6,1,1,4,5,6,1,1,1,2,5,2,1,1,3,1,5,4,3,1,5,3,1,6,1,5,2,1,3,4,1,2,3,1,6,1,2,5,1,2,3,4,3,1,4,1,1,1,5,6,1,5,1,4,1,3,5,3,2,1,1,2,5,1,1,4,3,5,1,2,3,4,1,1,5,1,3,4,1,1,6,5,1,3,2,1,5,1,4,3,1,6,1,5,3,2,1,6,5,2,3,4,1,6,1,4,1,1,5,1,4,3,2,5,4,1,2,3,5,1,3,1,4,1,5,1,2,3,1,5,4,1,1,3,5,1,1,4,3,2,1,5,4,1,5,2,1,1,3,5,1,1,5,3,1,1,1,4,1,3,4,3,2,5,1,4,1,2,1,3,2,1,1,3,5,4,3,1,1,5,2,1,3,5,1,4,1,3,5,1,1,4,1,2,5,3,2,1,5,1,2,5,1,1,3,4,3,1,3,1,1,2,1,4,1,2,1,1,4,1,3,4,1,4,1,3,1,1,3,1,1,2,1,1,3,1,1,3,1,4,1,4,3,1,4,1,1,1,4,1,2,1,1,3,1,3,4,1,1,2,1,4,1,3,2,1,4,1,1,2,1,1,3,1,3,1,1,4,3,1,1,2,3,1,2,1,1,3,4,1,1,3,1,1,4,1,2,3,4,1,3,1};

// ~2,5333 to 2.65, 14 frequencies
// !!! 350MHz Base: 886.654 MHz to 927.500 MHz
// !!! 300MHz Base: 760.000 MHz to 795.000 MHz
//volatile int m_values[] = {38, 61, 51, 64, 41, 54, 31, 57, 47, 21, 50, 58, 37, 53};
//volatile int d_values[] = {5, 6, 4, 5, 8, 7, 3, 11, 6, 4, 19, 11, 7, 5};
//volatile int o_values[] = {3, 4, 5, 5, 2, 3, 4, 2, 3, 2, 1, 2, 2, 4};


#endif /* MMCM_PARAMS_H_ */