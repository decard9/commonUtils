################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/process1.cpp \
../src/ubuntu_researchUtil2.cpp \
../src/utilCls2.cpp 

OBJS += \
./src/process1.o \
./src/ubuntu_researchUtil2.o \
./src/utilCls2.o 

CPP_DEPS += \
./src/process1.d \
./src/ubuntu_researchUtil2.d \
./src/utilCls2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/decard9/Documents/boost_1_57_0 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


