################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Date.cpp \
../src/Person.cpp \
../src/lab3.2-Aggregation.cpp 

OBJS += \
./src/Date.o \
./src/Person.o \
./src/lab3.2-Aggregation.o 

CPP_DEPS += \
./src/Date.d \
./src/Person.d \
./src/lab3.2-Aggregation.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


