################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Sedan.cpp \
../src/Vehicle.cpp \
../src/lab3.1-Inheritance.cpp 

OBJS += \
./src/Sedan.o \
./src/Vehicle.o \
./src/lab3.1-Inheritance.o 

CPP_DEPS += \
./src/Sedan.d \
./src/Vehicle.d \
./src/lab3.1-Inheritance.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


