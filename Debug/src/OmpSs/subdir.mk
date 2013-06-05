################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../src/OmpSs/OMPSSParser.cxx \
../src/OmpSs/OMPSSPlugin.cxx 

OBJS += \
./src/OmpSs/OMPSSParser.o \
./src/OmpSs/OMPSSPlugin.o 

CXX_DEPS += \
./src/OmpSs/OMPSSParser.d \
./src/OmpSs/OMPSSPlugin.d 


# Each subdirectory must supply rules for building sources it contributes
src/OmpSs/%.o: ../src/OmpSs/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


