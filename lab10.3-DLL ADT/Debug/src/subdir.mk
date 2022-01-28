################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/lab10.3-DLL\ ADT.cpp 

OBJS += \
./src/lab10.3-DLL\ ADT.o 

CPP_DEPS += \
./src/lab10.3-DLL\ ADT.d 


# Each subdirectory must supply rules for building sources it contributes
src/lab10.3-DLL\ ADT.o: ../src/lab10.3-DLL\ ADT.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/lab10.3-DLL ADT.d" -MT"src/lab10.3-DLL\ ADT.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


