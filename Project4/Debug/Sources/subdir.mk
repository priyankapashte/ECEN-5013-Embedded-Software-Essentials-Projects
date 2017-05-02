################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/analysis.c \
../Sources/circbuf.c \
../Sources/data.c \
../Sources/gpio.c \
../Sources/led.c \
../Sources/log.c \
../Sources/main.c \
../Sources/message.c \
../Sources/nordic.c \
../Sources/rtc.c \
../Sources/spi.c \
../Sources/uart.c 

OBJS += \
./Sources/analysis.o \
./Sources/circbuf.o \
./Sources/data.o \
./Sources/gpio.o \
./Sources/led.o \
./Sources/log.o \
./Sources/main.o \
./Sources/message.o \
./Sources/nordic.o \
./Sources/rtc.o \
./Sources/spi.o \
./Sources/uart.o 

C_DEPS += \
./Sources/analysis.d \
./Sources/circbuf.d \
./Sources/data.d \
./Sources/gpio.d \
./Sources/led.d \
./Sources/log.d \
./Sources/main.d \
./Sources/message.d \
./Sources/nordic.d \
./Sources/rtc.d \
./Sources/spi.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -Dtimestamp=`(date +%s)` -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


