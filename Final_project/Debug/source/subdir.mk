################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Final_project.c \
../source/adc.c \
../source/delay.c \
../source/led.c \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/timers.c \
../source/tmp_snsr.c 

C_DEPS += \
./source/Final_project.d \
./source/adc.d \
./source/delay.d \
./source/led.d \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/timers.d \
./source/tmp_snsr.d 

OBJS += \
./source/Final_project.o \
./source/adc.o \
./source/delay.o \
./source/led.o \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/timers.o \
./source/tmp_snsr.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\board" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\source" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\drivers" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\CMSIS" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\utilities" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/Final_project.d ./source/Final_project.o ./source/adc.d ./source/adc.o ./source/delay.d ./source/delay.o ./source/led.d ./source/led.o ./source/mtb.d ./source/mtb.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o ./source/timers.d ./source/timers.o ./source/tmp_snsr.d ./source/tmp_snsr.o

.PHONY: clean-source

