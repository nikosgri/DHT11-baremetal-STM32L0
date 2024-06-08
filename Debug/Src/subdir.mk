################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/rcc.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32l0xx.c 

OBJS += \
./Src/main.o \
./Src/rcc.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32l0xx.o 

C_DEPS += \
./Src/main.d \
./Src/rcc.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32l0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DNUCLEO_L053R8 -DSTM32 -DSTM32L0 -DSTM32L053R8Tx -DSTM32L053xx -c -I../Inc -I"/home/grego/STM32CubeIDE/workspace_1.13.1/DHT11_baremetal/CMSIS/Device/ST/STM32L0xx/Include" -I"/home/grego/STM32CubeIDE/workspace_1.13.1/DHT11_baremetal/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/rcc.cyclo ./Src/rcc.d ./Src/rcc.o ./Src/rcc.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_stm32l0xx.cyclo ./Src/system_stm32l0xx.d ./Src/system_stm32l0xx.o ./Src/system_stm32l0xx.su

.PHONY: clean-Src

