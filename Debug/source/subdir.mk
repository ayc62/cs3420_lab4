################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/3140_concur.c \
../source/lab4_l0.c \
../source/lock.c \
../source/process.c \
../source/utils.c 

S_SRCS += \
../source/3140.s 

C_DEPS += \
./source/3140_concur.d \
./source/lab4_l0.d \
./source/lock.d \
./source/process.d \
./source/utils.d 

OBJS += \
./source/3140.o \
./source/3140_concur.o \
./source/lab4_l0.o \
./source/lock.o \
./source/process.o \
./source/utils.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.s source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__REDLIB__ -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4\board" -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4\source" -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4" -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4\drivers" -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4\CMSIS" -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4\utilities" -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4\startup" -g3 -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL46Z256VLL4_cm0plus -DCPU_MKL46Z256VLL4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4\board" -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4\source" -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4" -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4\drivers" -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4\CMSIS" -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4\utilities" -I"C:\Users\alkim\Documents\MCUXpressoIDE_11.7.0_9198\workspace\3420_lab4\startup" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/3140.o ./source/3140_concur.d ./source/3140_concur.o ./source/lab4_l0.d ./source/lab4_l0.o ./source/lock.d ./source/lock.o ./source/process.d ./source/process.o ./source/utils.d ./source/utils.o

.PHONY: clean-source

