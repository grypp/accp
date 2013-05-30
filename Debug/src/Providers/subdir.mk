################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../src/Providers/CAPSACCFrontEndParser.cxx \
../src/Providers/CAPSACCGroupletParser.cxx \
../src/Providers/CAPSACCKernelParser.cxx 

OBJS += \
./src/Providers/CAPSACCFrontEndParser.o \
./src/Providers/CAPSACCGroupletParser.o \
./src/Providers/CAPSACCKernelParser.o 

CXX_DEPS += \
./src/Providers/CAPSACCFrontEndParser.d \
./src/Providers/CAPSACCGroupletParser.d \
./src/Providers/CAPSACCKernelParser.d 


# Each subdirectory must supply rules for building sources it contributes
src/Providers/%.o: ../src/Providers/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


