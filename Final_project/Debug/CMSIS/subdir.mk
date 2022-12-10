################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/system_MKL25Z4.c 

C_DEPS += \
./CMSIS/system_MKL25Z4.d 

OBJS += \
./CMSIS/system_MKL25Z4.o 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/%.o: ../CMSIS/%.c CMSIS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\board" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\source" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\drivers" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\CMSIS" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\utilities" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-CMSIS

clean-CMSIS:
	-$(RM) ./CMSIS/system_MKL25Z4.d ./CMSIS/system_MKL25Z4.o

.PHONY: clean-CMSIS

