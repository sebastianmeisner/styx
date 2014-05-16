----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:05:41 05/21/2013 
-- Design Name: 
-- Module Name:    InverterElem - Behavioral 
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

entity InverterElemP is
   Port ( 
		d : in  std_logic;
      clk : in  std_logic;
      q : out  std_logic;
		reset : in std_logic
	);
end InverterElemP;

architecture Behavioral of InverterElemP is

signal q_temp : std_logic;
signal reset_vec : std_logic_vector(9 downto 0);
signal reset_end : std_logic;


begin
	
	reset_vec(9) <= reset;
	reset_end <= reset_vec(0);
	

	process (d, clk, reset_end)
	begin
		-- FlipFlop mit Reset-Leitung
		if(reset_end = '1') then
			q_temp <= '1';
		elsif(rising_edge(clk)) then
			q_temp <= d;
		end if;
	end process;
	
	process (clk) 
	begin
		if(rising_edge(clk)) then
			for i in 9 downto 1 loop
				reset_vec(i-1) <= reset_vec(i);
			end loop ;
		end if;
	end process;
	
	-- INVERTER:
	q <= not q_temp;

end Behavioral;

