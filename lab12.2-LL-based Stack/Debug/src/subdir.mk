################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/lab12.2-LL-based\ Stack.cpp 

OBJS += \
./src/lab12.2-LL-based\ Stack.o 

CPP_DEPS += \
./src/lab12.2-LL-based\ Stack.d 


# Each subdirectory must supply rules for building sources it contributes
src/lab12.2-LL-based\ Stack.o: ../src/lab12.2-LL-based\ Stack.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/lab12.2-LL-based Stack.d" -MT"src/lab12.2-LL-based\ Stack.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


