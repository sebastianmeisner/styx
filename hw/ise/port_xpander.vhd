----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:12:33 07/24/2014 
-- Design Name: 
-- Module Name:    port_xpander - Behavioral 
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

entity port_xpander is
    Port ( IN1 : in  STD_LOGIC;
           OUT1 : out  STD_LOGIC;
           OUT2 : out  STD_LOGIC);
end port_xpander;

architecture Behavioral of port_xpander is

signal temp : std_logic;

begin
   temp <= IN1;
   OUT1 <= temp;
   OUT2 <= temp;


end Behavioral;

