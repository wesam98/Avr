################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LM35/LM_Config.c \
../HAL/LM35/LM_Prog.c 

OBJS += \
./HAL/LM35/LM_Config.o \
./HAL/LM35/LM_Prog.o 

C_DEPS += \
./HAL/LM35/LM_Config.d \
./HAL/LM35/LM_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LM35/%.o: ../HAL/LM35/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


