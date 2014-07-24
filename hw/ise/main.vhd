----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:35:35 05/14/2013 
-- Design Name: 
-- Module Name:    main - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_MISC.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity main is
	port (
		SYSCLK_N 		: in 		std_logic;
		SYSCLK_P 		: in 		std_logic;
		USB_1_RX 		: in 		std_logic;
		USB_1_TX 		: out 	std_logic;
		CPU_RESET		: in 		std_logic;
		gpio_led_0		: out 	std_logic;
		gpio_led_1		: out 	std_logic;
		gpio_led_2		: out 	std_logic;
		gpio_led_3		: out 	std_logic;
		gpio_led_4		: out 	std_logic;
		gpio_led_5		: out 	std_logic
	);
end main;

architecture Behavioral of main is

-- CLOCKING WIZARD (MCS & TC) SIGNALS
signal clk_out_mcs 	: std_logic;
signal clk_out_clktc : std_logic;
signal clk_out_clktc1 : std_logic;
signal clk_out_tc		: std_logic;
signal LOCKED_RISING		: std_logic;
signal LOCKED_FALLING		: std_logic;
signal LOCKED1_RISING		: std_logic;
signal LOCKED1_FALLING		: std_logic;
signal LOCKED0 	: std_logic;
signal LOCKED1 	: std_logic;
signal LOCKED_B 	: std_logic;
signal clkreset 		: std_logic;
signal stop 			: STD_LOGIC := '0';

-- CLOCKING WIZARD (TC) DRP SIGNALS
signal DADDR_TC 		: std_logic_vector(6 downto 0);
signal DEN_TC 			: std_logic;
signal DIN_TC 			: std_logic_vector(15 downto 0);
signal DOUT 		: std_logic_vector(15 downto 0);
signal DRDY 		: std_logic;
signal DWE_TC 			: std_logic;

-- ZERO SIGNALS / BUS
signal zero16 : std_logic_vector(15 downto 0) := "0000000000000000";
signal zero2 : std_logic_vector(1 downto 0) := "00";
signal zero23 : std_logic_vector(22 downto 0) := "00000000000000000000000";
signal zero128 : std_logic_vector(127 downto 0) := (others => '0');
signal one128 : std_logic_vector(127 downto 0) := (others => '1');
signal zero30	:	std_logic_vector(29 downto 0) := (others => '0');
signal zero12	:	std_logic_vector(11 downto 0) := (others => '0');
-- MCS SIGNALS
signal UART_Interrupt: std_logic;
signal FIT1_Interrupt: std_logic;
signal FIT1_Toggle	: std_logic;
signal FIT2_Interrupt: std_logic;
signal FIT2_Toggle	: std_logic;
signal GPO1 			: std_logic_vector(31 downto 0);
signal GPO2 			: std_logic_vector(31 downto 0);
signal GPO3 			: std_logic_vector(31 downto 0);
signal GPO4 			: std_logic_vector(31 downto 0);
signal GPI1 			: std_logic_vector(31 downto 0);
signal GPI2 			: std_logic_vector(31 downto 0);
signal GPI3 			: std_logic_vector(31 downto 0);
signal GPI4 			: std_logic_vector(31 downto 0);
signal GPI1_Interrupt: std_logic;
signal GPI2_Interrupt: std_logic;
signal GPI3_Interrupt: std_logic;
signal GPI4_Interrupt: std_logic;
signal INTC_Interrupt: std_logic_vector(15 downto 0);
signal INTC_IRQ		: std_logic ;
signal empty 			: std_logic;
signal empty_enable 	: std_logic_vector(3 downto 0);

signal IO_Addr_Strobe 	: STD_LOGIC;
signal IO_Read_Strobe 	: STD_LOGIC;
signal IO_Write_Strobe	: STD_LOGIC;
signal IO_Address 		: std_logic_vector(31 downto 0);
signal IO_Byte_Enable	: STD_LOGIC_VECTOR(3 DOWNTO 0);
signal IO_Write_Data 	: std_logic_vector(31 downto 0);
signal IO_Read_Data 		: std_logic_vector(31 downto 0);
signal IO_Ready 			: STD_LOGIC;

-- HEATER SIGNALS
signal enable_vector 	: STD_LOGIC_VECTOR(5 downto 0);
signal heater_array_bus : STD_LOGIC_VECTOR(5 downto 0);
signal led_bus 			: std_logic_vector(5 downto 0);

-- MUX SIGNALS
signal GPO1_1to0			: std_logic_vector(1 downto 0);
signal DEN_t				: std_logic_vector(3 downto 0);

-- TEST CIRCUIT SIGNALS
signal ser_out 		: std_logic_vector(127 downto 0);
signal tcreset			: std_logic;

component mux4_1
port (
	i0 			: in std_logic;
   i1 			: in std_logic;
   i2 			: in std_logic;
   i3 			: in std_logic;
   sel 			: in std_logic_vector(1 downto 0);
   bitout 		: out std_logic
);
end component;

component port_xpander
Port ( 
	IN1 			: in  STD_LOGIC;
	OUT1 			: out  STD_LOGIC;
	OUT2 			: out  STD_LOGIC
);
end component;


component clkwizard
port (
	CLK_IN1_P         	: in     std_logic;
	CLK_IN1_N         	: in     std_logic;
	CLK_OUT1          	: out    std_logic;
	CLK_OUT2          	: out    std_logic;
	RESET             	: in     std_logic;
	LOCKED            	: out    std_logic
);
end component;

component clkwizard_testcircuit
port (
	CLK_IN1           	: in     std_logic;
	CLK_OUT1          	: out    std_logic;
	DADDR          		: in     std_logic_vector( 6 downto 0);
	DCLK           		: in     std_logic;
	DEN            		: in     std_logic;
	DIN               	: in     std_logic_vector(15 downto 0);
	DOUT              	: out    std_logic_vector(15 downto 0);
	DWE               	: in     std_logic;
	DRDY              	: out    std_logic;
	RESET             	: in     std_logic;
	POWER_DOWN        	: in     std_logic;
	LOCKED            	: out    std_logic
);
end component;

component dut_monitor
port (
	Clk					: IN 		STD_LOGIC;
	Reset				: IN 		STD_LOGIC;
	IO_Addr_Strobe 		: OUT 	STD_LOGIC;
	IO_Read_Strobe 		: OUT 	STD_LOGIC;
	IO_Write_Strobe		: OUT 	STD_LOGIC;
	IO_Address 			: OUT 	STD_LOGIC_VECTOR(31 DOWNTO 0);
	IO_Byte_Enable 		: OUT 	STD_LOGIC_VECTOR(3 DOWNTO 0);
	IO_Write_Data 		: OUT 	STD_LOGIC_VECTOR(31 DOWNTO 0);
	IO_Read_Data 		: IN 		STD_LOGIC_VECTOR(31 DOWNTO 0);
	IO_Ready 			: IN 		STD_LOGIC;
	UART_Rx 			: IN 		STD_LOGIC;
	UART_Tx 			: OUT 	STD_LOGIC;
	FIT1_Interrupt 		: OUT 	STD_LOGIC;
	FIT1_Toggle 		: OUT 	STD_LOGIC;
	FIT2_Interrupt 		: OUT 	STD_LOGIC;
	FIT2_Toggle 		: OUT 	STD_LOGIC;
	GPO1 				: OUT 	STD_LOGIC_VECTOR(31 DOWNTO 0);
	GPO2 				: OUT 	STD_LOGIC_VECTOR(31 DOWNTO 0);
	GPO3 				: OUT 	STD_LOGIC_VECTOR(31 DOWNTO 0);
	GPO4 				: OUT 	STD_LOGIC_VECTOR(31 DOWNTO 0);
	GPI1 				: IN 		STD_LOGIC_VECTOR(31 DOWNTO 0);
	GPI2 				: IN 		STD_LOGIC_VECTOR(31 DOWNTO 0);
	GPI3 				: IN 		STD_LOGIC_VECTOR(31 DOWNTO 0);
	GPI4 				: IN 		STD_LOGIC_VECTOR(31 DOWNTO 0);
	GPI1_Interrupt 		: OUT 	STD_LOGIC;
	GPI2_Interrupt 		: OUT 	STD_LOGIC;
	GPI3_Interrupt 		: OUT 	STD_LOGIC;
	GPI4_Interrupt 		: OUT 	STD_LOGIC;
	INTC_Interrupt 		: IN 		STD_LOGIC_VECTOR(15 DOWNTO 0);
	INTC_IRQ 			: OUT 	STD_LOGIC
);
end component;


component InverterChain
generic (n: positive range 2 to 16384 := 1024);
port(
	clk 				: in 		std_logic; 
	rst 				: in 		std_logic;
	intr_out 			: out	 	std_logic_vector(127 downto 0)
);
end component;

COMPONENT counter
PORT(
	clock 				: IN 		std_logic;  
	reset				: IN		std_logic;
	Q 					: OUT 	std_logic
);
END COMPONENT;

COMPONENT heater_0
PORT(
	enable : IN std_logic;
	out_value : OUT std_logic;
	out_status : OUT std_logic
);
END COMPONENT;

COMPONENT heater_1
PORT(
	enable : IN std_logic;
	out_value : OUT std_logic;
	out_status : OUT std_logic
);
END COMPONENT;

COMPONENT heater_2
PORT(
	enable : IN std_logic;
	out_value : OUT std_logic;
	out_status : OUT std_logic
);
END COMPONENT;

COMPONENT heater_3
PORT(
	enable : IN std_logic;
	out_value : OUT std_logic;
	out_status : OUT std_logic
);
END COMPONENT;

COMPONENT heater_4
PORT(
	enable : IN std_logic;
	out_value : OUT std_logic;
	out_status : OUT std_logic
);
END COMPONENT;

COMPONENT heater_5
PORT(
	enable : IN std_logic;
	out_value : OUT std_logic;
	out_status : OUT std_logic
);
END COMPONENT;


begin

MMCM_Selector : mux4_1
port map (
	i0					=>	DEN_t(0),
	i1					=>	DEN_t(1),
	i2					=>	DEN_t(2),
	i3					=>	DEN_t(3),
	sel				=>	GPO1_1to0,
	bitout			=>	DEN_TC
);

LOCKED_MMCM0	: port_xpander
Port map( 
	IN1 			=>		LOCKED0,
	OUT1 			=>		LOCKED_RISING,
	OUT2 			=>		LOCKED_FALLING
);

LOCKED_MMCM1	: port_xpander
Port map( 
	IN1 			=>		LOCKED1,
	OUT1 			=>		LOCKED1_RISING,
	OUT2 			=>		LOCKED1_FALLING
);

clock_ins: clkwizard
port map (
	CLK_IN1_P 		=> 	SYSCLK_P,
	CLK_IN1_N 		=> 	SYSCLK_N,
	CLK_OUT1 		=> 	CLK_OUT_MCS,
	CLK_OUT2 		=> 	CLK_OUT_CLKTC,
	RESET  			=> 	CPU_RESET,
	LOCKED 			=> 	LOCKED_B
);
  
clock_testcircuit_ins : clkwizard_testcircuit
port map (
	CLK_IN1 			=> 	CLK_OUT_CLKTC,
   CLK_OUT1 		=> 	CLK_OUT_CLKTC1,
   DADDR  			=> 	DADDR_TC,
   DCLK   			=> 	CLK_OUT_MCS,
   DEN    			=> 	DEN_t(0),
   DIN    			=> 	DIN_TC,
   DOUT   			=> 	DOUT,
   DRDY   			=> 	DRDY,
   DWE    			=> 	DWE_TC,
   RESET  			=> 	clkreset,
	POWER_DOWN 		=> 	stop,
   LOCKED 			=> 	LOCKED0
);

clock_testcircuit_ins1 : clkwizard_testcircuit
port map (
	CLK_IN1 			=> 	CLK_OUT_CLKTC1,
   CLK_OUT1 		=> 	CLK_OUT_TC,
   DADDR  			=> 	DADDR_TC,
   DCLK   			=> 	CLK_OUT_MCS,
   DEN    			=> 	DEN_t(1),
   DIN    			=> 	DIN_TC,
   DOUT   			=> 	DOUT,
   DWE    			=> 	DWE_TC,
   DRDY   			=> 	DRDY,
   RESET  			=> 	clkreset,
	POWER_DOWN 		=> 	stop,
   LOCKED 			=> 	LOCKED1
);

dut_monitor_ins : dut_monitor
port map(
	Clk 									=> 	clk_out_mcs,
   Reset 								=> 	CPU_Reset,
	IO_Addr_Strobe 					=> 	IO_Addr_Strobe,
   IO_Read_Strobe 					=>		IO_Read_Strobe,
   IO_Write_Strobe					=> 	DWE_TC,
	IO_Address(31 downto 9)			=>		zero23,
   IO_Address(8 downto 2) 			=> 	DADDR_TC,
	IO_Address(1 downto 0) 			=>		zero2,
   IO_Byte_Enable 					=> 	DEN_t,
   IO_Write_Data(31 downto 16) 	=> 	zero16,--IO_Write_Data,
	IO_Write_Data(15 downto 0) 	=>		DIN_TC,
   --IO_Read_Data(31 downto 16) 	=> 	zero16,--IO_Read_Data,
	--IO_Read_Data(15 downto 0) 		=>		DOUT_TC,
   IO_Read_Data						=>		IO_Read_Data,
	IO_Ready 							=> 	IO_Ready,
   UART_Rx 								=> 	USB_1_RX,
   UART_Tx 								=> 	USB_1_TX,
	FIT1_Interrupt 					=> 	FIT1_Interrupt,
   FIT1_Toggle 						=> 	FIT1_Toggle,
	FIT2_Interrupt 					=> 	FIT2_Interrupt,
   FIT2_Toggle 						=> 	FIT2_Toggle,
   GPO1(1 downto 0)					=> 	GPO1_1to0,	-- MUX channel selector for enabling MMCM through DEN signal
	GPO1(31 downto 2)					=>		zero30,
	GPO2 									=> 	GPO2,
	GPO3 									=> 	GPO3,
	GPO4 									=> 	GPO4,
   GPI1 									=> 	GPI1,
	GPI2 									=> 	GPI2,
	GPI3 									=> 	GPI3,
	GPI4 									=> 	GPI4,
   GPI1_Interrupt 					=> 	GPI1_Interrupt,
	GPI2_Interrupt 					=> 	GPI2_Interrupt,
	GPI3_Interrupt 					=> 	GPI3_Interrupt,
	GPI4_Interrupt 					=> 	GPI4_Interrupt,
	INTC_Interrupt(0)					=> 	LOCKED_RISING,
	INTC_Interrupt(1)					=>		LOCKED_FALLING,
	INTC_Interrupt(2)					=> 	LOCKED1_RISING,
	INTC_Interrupt(3)					=>		LOCKED1_FALLING,
	INTC_Interrupt(15 downto 4)	=>		zero12,
	INTC_IRQ 							=> 	INTC_IRQ
);
  
test_circuit_ins : InverterChain
generic map(
	n 					=> 	1024
)
port map (
	clk 				=> 	CLK_OUT_TC,
	rst 				=> 	tcreset,
	intr_out 		=> 	ser_out
);	 
	
counter_ins: counter 
PORT MAP(
	clock 			=> 	clk_out_tc,
	reset				=>		GPO1(2),
	Q 					=> 	INTC_Interrupt(14)
);


heater_0_ins: heater_0 
PORT MAP(
	enable => '1',
	out_value => heater_array_bus(0),
	out_status => led_bus(0)
);	 

heater_1_ins: heater_1
PORT MAP(
	enable => '1',
	out_value => heater_array_bus(1),
	out_status => led_bus(1)
);	 

heater_2_ins: heater_2
PORT MAP(
	enable => '1',
	out_value => heater_array_bus(2),
	out_status => led_bus(2)
);	 

heater_3_ins: heater_3 
PORT MAP(
	enable => '1',
	out_value => heater_array_bus(3),
	out_status => led_bus(3)
);	 

heater_4_ins: heater_4 
PORT MAP(
	enable => '1',
	out_value => heater_array_bus(4),
	out_status => led_bus(4)
);	

heater_5_ins: heater_5
PORT MAP(
	enable => '1',
	out_value => heater_array_bus(5),
	out_status => led_bus(5)
);	


GPO2(5 downto 0) <= enable_vector;
GPO2(31 downto 6) <= (others => '0');

-- SET GPI SIGNALS
GPI1 <= ser_out(31 downto 0);
GPI2 <= ser_out(63 downto 32);
GPI3 <= ser_out(95 downto 64);
GPI4 <= ser_out(127 downto 96);

-- LEDs for HEATERS
gpio_led_0 <= led_bus(0);
gpio_led_1 <= led_bus(1);
gpio_led_2 <= led_bus(2);
gpio_led_3 <= led_bus(3);
gpio_led_4 <= led_bus(4);
gpio_led_5 <= led_bus(5) OR AND_REDUCE(heater_array_bus);


-- Interrupt and Resets
clkreset 			<= GPO1(0); -- mit GPO1 = 1 wird clkreset aktiv
tcreset 				<= GPO1(1);	-- mit GPO1 = 2 wird tcreset aktiv
										-- mit GPO1 = 4 wird Counter Reset aktiv
  
INTC_Interrupt(13) <= tcreset;
INTC_Interrupt(12) <= clkreset;
  
process (clk_out_tc)
begin
	if(clk_out_tc = '1' and clk_out_tc'event) then
		INTC_Interrupt(15) <= ser_out(0) xor ser_out(1);
	end if;
end process;

end Behavioral;
