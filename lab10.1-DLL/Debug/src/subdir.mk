################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/lab10.1-DLL\ copy.cpp \
../src/lab10.1-DLL.cpp 

OBJS += \
./src/lab10.1-DLL\ copy.o \
./src/lab10.1-DLL.o 

CPP_DEPS += \
./src/lab10.1-DLL\ copy.d \
./src/lab10.1-DLL.d 


# Each subdirectory must supply rules for building sources it contributes
src/lab10.1-DLL\ copy.o: ../src/lab10.1-DLL\ copy.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/lab10.1-DLL copy.d" -MT"src/lab10.1-DLL\ copy.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


