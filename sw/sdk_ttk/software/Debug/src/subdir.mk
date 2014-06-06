################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/helloworld.c \
../src/platform.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/helloworld.o \
./src/platform.o 

C_DEPS += \
./src/helloworld.d \
./src/platform.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MicroBlaze gcc compiler'
	mb-gcc -Wall -O0 -g3 -I../../software_bsp/dut_monitor/include -I"C:\Xilinx\14.5\ISE_DS\EDK\gnu\microblaze\nt64\lib\gcc\microblaze-xilinx-elf\4.6.2\include" -I"C:\Xilinx\14.5\ISE_DS\EDK\gnu\microblaze\nt64\lib\gcc\microblaze-xilinx-elf\4.6.2\include-fixed" -I"C:\Xilinx\14.5\ISE_DS\EDK\gnu\microblaze\nt64\microblaze-xilinx-elf\include" -c -fmessage-length=0 -Wl,--no-relax -mno-xl-reorder -mlittle-endian -mcpu=v8.40.a -mxl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


