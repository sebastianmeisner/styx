################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
software.elf.size \

ELFCHECK += \
software.elf.elfcheck \


# All Target
all: software.elf secondary-outputs

# Tool invocations
software.elf: $(OBJS) ../src/lscript.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MicroBlaze gcc linker'
	mb-gcc -Wl,--no-relax -Wl,-T -Wl,../src/lscript.ld -L../../software_bsp/dut_monitor/lib -mlittle-endian -mcpu=v8.40.a -mxl-soft-mul -o "software.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

software.elf.size: software.elf
	@echo 'Invoking: MicroBlaze Print Size'
	mb-size software.elf  |tee "software.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

software.elf.elfcheck: software.elf
	@echo 'Invoking: Xilinx ELF Check'
	elfcheck software.elf -hw ../../ttk/system.xml -pe dut_monitor  |tee "software.elf.elfcheck"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES)$(ELFSIZE)$(ELFCHECK)$(S_UPPER_DEPS) software.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE) $(ELFCHECK)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
