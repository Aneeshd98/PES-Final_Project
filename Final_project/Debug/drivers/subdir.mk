################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_flash.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lpsci.c \
../drivers/fsl_smc.c \
../drivers/fsl_uart.c 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_flash.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lpsci.d \
./drivers/fsl_smc.d \
./drivers/fsl_uart.d 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_flash.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpsci.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\board" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\source" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\drivers" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\CMSIS" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\utilities" -I"C:\Users\HP\Documents\MCUXpressoIDE_11.6.0_8187\Final_project\Final_project\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_flash.d ./drivers/fsl_flash.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_lpsci.d ./drivers/fsl_lpsci.o ./drivers/fsl_smc.d ./drivers/fsl_smc.o ./drivers/fsl_uart.d ./drivers/fsl_uart.o

.PHONY: clean-drivers

