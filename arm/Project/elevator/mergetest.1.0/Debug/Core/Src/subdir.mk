################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Ap.c \
../Core/Src/Button.c \
../Core/Src/Buzz.c \
../Core/Src/LED.c \
../Core/Src/Photo.c \
../Core/Src/State.c \
../Core/Src/fnd.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/lcd_i2c.c \
../Core/Src/main.c \
../Core/Src/motor.c \
../Core/Src/stepper1.c \
../Core/Src/stepper2.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/tim.c 

OBJS += \
./Core/Src/Ap.o \
./Core/Src/Button.o \
./Core/Src/Buzz.o \
./Core/Src/LED.o \
./Core/Src/Photo.o \
./Core/Src/State.o \
./Core/Src/fnd.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/lcd_i2c.o \
./Core/Src/main.o \
./Core/Src/motor.o \
./Core/Src/stepper1.o \
./Core/Src/stepper2.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/tim.o 

C_DEPS += \
./Core/Src/Ap.d \
./Core/Src/Button.d \
./Core/Src/Buzz.d \
./Core/Src/LED.d \
./Core/Src/Photo.d \
./Core/Src/State.d \
./Core/Src/fnd.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/lcd_i2c.d \
./Core/Src/main.d \
./Core/Src/motor.d \
./Core/Src/stepper1.d \
./Core/Src/stepper2.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Ap.cyclo ./Core/Src/Ap.d ./Core/Src/Ap.o ./Core/Src/Ap.su ./Core/Src/Button.cyclo ./Core/Src/Button.d ./Core/Src/Button.o ./Core/Src/Button.su ./Core/Src/Buzz.cyclo ./Core/Src/Buzz.d ./Core/Src/Buzz.o ./Core/Src/Buzz.su ./Core/Src/LED.cyclo ./Core/Src/LED.d ./Core/Src/LED.o ./Core/Src/LED.su ./Core/Src/Photo.cyclo ./Core/Src/Photo.d ./Core/Src/Photo.o ./Core/Src/Photo.su ./Core/Src/State.cyclo ./Core/Src/State.d ./Core/Src/State.o ./Core/Src/State.su ./Core/Src/fnd.cyclo ./Core/Src/fnd.d ./Core/Src/fnd.o ./Core/Src/fnd.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/i2c.cyclo ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/lcd_i2c.cyclo ./Core/Src/lcd_i2c.d ./Core/Src/lcd_i2c.o ./Core/Src/lcd_i2c.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/motor.cyclo ./Core/Src/motor.d ./Core/Src/motor.o ./Core/Src/motor.su ./Core/Src/stepper1.cyclo ./Core/Src/stepper1.d ./Core/Src/stepper1.o ./Core/Src/stepper1.su ./Core/Src/stepper2.cyclo ./Core/Src/stepper2.d ./Core/Src/stepper2.o ./Core/Src/stepper2.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/tim.cyclo ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su

.PHONY: clean-Core-2f-Src

