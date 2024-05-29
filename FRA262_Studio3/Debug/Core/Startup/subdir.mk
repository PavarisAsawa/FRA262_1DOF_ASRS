################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32g474retx.s 

OBJS += \
./Core/Startup/startup_stm32g474retx.o 

S_DEPS += \
./Core/Startup/startup_stm32g474retx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/BasicMathFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/BayesFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/CommonTables" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/ComplexMathFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/ControllerFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/DistanceFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/FastMathFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/FilteringFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/InterpolationFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/MatrixFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/QuaternionMathFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/StatisticsFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/SupportFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/SVMFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/TransformFunctions" -I"C:/Users/emper/STM32CubeIDE/workspace_1.14.1/FRA262_1DOF_ASRS/FRA262_Studio3/Source/WindowFunctions" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32g474retx.d ./Core/Startup/startup_stm32g474retx.o

.PHONY: clean-Core-2f-Startup

