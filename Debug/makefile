################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
testmoijejcierpliwosc.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
testmoijejcierpliwosc.list \

OBJCOPY_BIN += \
testmoijejcierpliwosc.bin \


# All Target
all: testmoijejcierpliwosc.elf secondary-outputs

# Tool invocations
testmoijejcierpliwosc.elf: $(OBJS) $(USER_OBJS) F:\Users\Maciej\STM32CubeIDE\workspace_1.3.0\testmoijejcierpliwosc\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "testmoijejcierpliwosc.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"F:\Users\Maciej\STM32CubeIDE\workspace_1.3.0\testmoijejcierpliwosc\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="testmoijejcierpliwosc.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

testmoijejcierpliwosc.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "testmoijejcierpliwosc.list"
	@echo 'Finished building: $@'
	@echo ' '

testmoijejcierpliwosc.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "testmoijejcierpliwosc.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
