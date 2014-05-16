----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:41:39 06/29/2013 
-- Design Name: 
-- Module Name:    ClockStopper - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ClockStopper is
    Port ( in_tc : in  STD_LOGIC;
           in_re : in  STD_LOGIC;
           stop : out  STD_LOGIC;
			  clk : in std_logic);
end ClockStopper;

architecture Behavioral of ClockStopper is

signal conn : std_logic;

begin

	if(clk'event and (clk = "1" or clk = "0")) then
		stop <= in_tc or in_re;
		in_re <= stop;
			

end Behavioral;

