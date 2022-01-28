################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/dateType.cpp \
../src/extDateType.cpp \
../src/program3.cpp 

OBJS += \
./src/dateType.o \
./src/extDateType.o \
./src/program3.o 

CPP_DEPS += \
./src/dateType.d \
./src/extDateType.d \
./src/program3.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


