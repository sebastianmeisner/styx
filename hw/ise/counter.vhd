library ieee ;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

----------------------------------------------------

entity counter is

port(	
	clock	:	in std_logic;
	reset	: 	in std_logic;
	Q		:	out std_logic
);
end counter;

----------------------------------------------------

architecture behv of counter is		 	  
	
	signal Pre_Q : std_logic := '0';
	signal cnt : integer := 0;
	

begin

   process(clock, reset)
	begin
		if(reset = '1') then
			Pre_Q <= '0';
		elsif (clock'event and clock = '1') then
			cnt <= cnt+1;
			if(cnt >= 100000000) then
				Pre_Q <= '1';
				cnt <= 0;
			end if;
		end if;
    end process;	
	
    Q <= Pre_Q;

end behv;
