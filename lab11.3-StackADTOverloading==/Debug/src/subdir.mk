################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/lab11.3-StackADTOverloading==.cpp 

OBJS += \
./src/lab11.3-StackADTOverloading==.o 

CPP_DEPS += \
./src/lab11.3-StackADTOverloading==.d 


# Each subdirectory must supply rules for building sources it contributes
src/lab11.3-StackADTOverloading==.o: ../src/lab11.3-StackADTOverloading==.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/lab11.3-StackADTOverloading==.d" -MT"src/lab11.3-StackADTOverloading==.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


