################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../src/ACCParser.cxx \
../src/ACCParserUtils.cxx \
../src/CUDAFunctions.cxx 

OBJS += \
./src/ACCParser.o \
./src/ACCParserUtils.o \
./src/CUDAFunctions.o 

CXX_DEPS += \
./src/ACCParser.d \
./src/ACCParserUtils.d \
./src/CUDAFunctions.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


