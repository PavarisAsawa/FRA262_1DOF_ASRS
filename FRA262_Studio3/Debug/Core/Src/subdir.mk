################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BaseSystem.c \
../Core/Src/Controller.c \
../Core/Src/Encoder.c \
../Core/Src/Joystick.c \
../Core/Src/KalmanFilter.c \
../Core/Src/ModbusRTU.c \
../Core/Src/ModeHandler.c \
../Core/Src/QuinticTrajectory.c \
../Core/Src/TrapezoidalTrajectory.c \
../Core/Src/main.c \
../Core/Src/stm32g4xx_hal_msp.c \
../Core/Src/stm32g4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32g4xx.c 

OBJS += \
./Core/Src/BaseSystem.o \
./Core/Src/Controller.o \
./Core/Src/Encoder.o \
./Core/Src/Joystick.o \
./Core/Src/KalmanFilter.o \
./Core/Src/ModbusRTU.o \
./Core/Src/ModeHandler.o \
./Core/Src/QuinticTrajectory.o \
./Core/Src/TrapezoidalTrajectory.o \
./Core/Src/main.o \
./Core/Src/stm32g4xx_hal_msp.o \
./Core/Src/stm32g4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32g4xx.o 

C_DEPS += \
./Core/Src/BaseSystem.d \
./Core/Src/Controller.d \
./Core/Src/Encoder.d \
./Core/Src/Joystick.d \
./Core/Src/KalmanFilter.d \
./Core/Src/ModbusRTU.d \
./Core/Src/ModeHandler.d \
./Core/Src/QuinticTrajectory.d \
./Core/Src/TrapezoidalTrajectory.d \
./Core/Src/main.d \
./Core/Src/stm32g4xx_hal_msp.d \
./Core/Src/stm32g4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32g4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/PrivateInclude/ -I../Middlewares/Third_Party/ARM_CMSIS/Include/ -I../Middlewares/Third_Party/ARM_CMSIS/Include -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/BasicMathFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/BayesFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/CommonTables" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/ComplexMathFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/ControllerFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/DistanceFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/FastMathFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/FilteringFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/InterpolationFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/MatrixFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/QuaternionMathFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/StatisticsFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/SupportFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/SVMFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/TransformFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/WindowFunctions" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/BaseSystem.cyclo ./Core/Src/BaseSystem.d ./Core/Src/BaseSystem.o ./Core/Src/BaseSystem.su ./Core/Src/Controller.cyclo ./Core/Src/Controller.d ./Core/Src/Controller.o ./Core/Src/Controller.su ./Core/Src/Encoder.cyclo ./Core/Src/Encoder.d ./Core/Src/Encoder.o ./Core/Src/Encoder.su ./Core/Src/Joystick.cyclo ./Core/Src/Joystick.d ./Core/Src/Joystick.o ./Core/Src/Joystick.su ./Core/Src/KalmanFilter.cyclo ./Core/Src/KalmanFilter.d ./Core/Src/KalmanFilter.o ./Core/Src/KalmanFilter.su ./Core/Src/ModbusRTU.cyclo ./Core/Src/ModbusRTU.d ./Core/Src/ModbusRTU.o ./Core/Src/ModbusRTU.su ./Core/Src/ModeHandler.cyclo ./Core/Src/ModeHandler.d ./Core/Src/ModeHandler.o ./Core/Src/ModeHandler.su ./Core/Src/QuinticTrajectory.cyclo ./Core/Src/QuinticTrajectory.d ./Core/Src/QuinticTrajectory.o ./Core/Src/QuinticTrajectory.su ./Core/Src/TrapezoidalTrajectory.cyclo ./Core/Src/TrapezoidalTrajectory.d ./Core/Src/TrapezoidalTrajectory.o ./Core/Src/TrapezoidalTrajectory.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32g4xx_hal_msp.cyclo ./Core/Src/stm32g4xx_hal_msp.d ./Core/Src/stm32g4xx_hal_msp.o ./Core/Src/stm32g4xx_hal_msp.su ./Core/Src/stm32g4xx_it.cyclo ./Core/Src/stm32g4xx_it.d ./Core/Src/stm32g4xx_it.o ./Core/Src/stm32g4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32g4xx.cyclo ./Core/Src/system_stm32g4xx.d ./Core/Src/system_stm32g4xx.o ./Core/Src/system_stm32g4xx.su

.PHONY: clean-Core-2f-Src

