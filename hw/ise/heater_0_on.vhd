----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:37:52 08/15/2013 
-- Design Name: 
-- Module Name:    heater - Behavioral 
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
use IEEE.STD_LOGIC_misc.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity heater_0 is
port
(
	  enable : in std_logic;
	  out_value : out std_logic;
	  out_status : out std_logic
);
end heater_0;

architecture Behavioral of heater_0 is


constant C_NUM_LUTS : integer := 1500;
signal inout_vector  : std_logic_vector(0 to C_NUM_LUTS-1);


COMPONENT lut_oscilator
PORT(
	en : IN std_logic;          
	Q : OUT std_logic
	);
END COMPONENT;

begin


pipeline : for bit_index in 0 to C_NUM_LUTS - 1 generate
begin
		lut_osc : lut_oscilator
		port map (    
			en     => 	'1',--enable and adjust(bit_index mod 32),--enable,
			Q      => 	inout_vector(bit_index)
		);		 
end generate pipeline;


out_value <= AND_REDUCE(inout_vector);

out_status <= '1';


end Behavioral;

