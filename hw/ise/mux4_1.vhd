----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:32:52 07/22/2014 
-- Design Name: 
-- Module Name:    mux4_1 - Behavioral 
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

entity mux4_1 is
port (
      i0 : in std_logic;
      i1 : in std_logic;
      i2 : in std_logic;
      i3 : in std_logic;
     sel : in std_logic_vector(1 downto 0);
     bitout : out std_logic
     );
end mux4_1;

architecture Behavioral of mux4_1 is
begin

process(i0,i1,i2,i3,sel)
begin
case sel is
  when "00" => bitout <= i0;
  when "01" => bitout <= i1;
  when "10" => bitout <= i2;
  when others => bitout <= i3;
end case;
end process;

end Behavioral;