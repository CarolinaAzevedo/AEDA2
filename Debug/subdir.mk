################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/eduardacunha/Desktop/Projeto\ 2\ 5.42.57\ PM/Menus.cpp \
/Users/eduardacunha/Desktop/Projeto\ 2\ 5.42.57\ PM/Person.cpp \
/Users/eduardacunha/Desktop/Projeto\ 2\ 5.42.57\ PM/Saves.cpp \
/Users/eduardacunha/Desktop/Projeto\ 2\ 5.42.57\ PM/Season.cpp \
/Users/eduardacunha/Desktop/Projeto\ 2\ 5.42.57\ PM/TheVoice.cpp \
/Users/eduardacunha/Desktop/Projeto\ 2\ 5.42.57\ PM/main.cpp 

OBJS += \
./Menus.o \
./Person.o \
./Saves.o \
./Season.o \
./TheVoice.o \
./main.o 

CPP_DEPS += \
./Parte2.d \
./Person.d \
./Saves.d \
./Season.d \
./TheVoice.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
Menus.o: /Users/eduardacunha/Desktop/Projeto\ 2\ 5.42.57\ PM/Menus.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"Parte2.d" -MT"Parte2.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Person.o: /Users/eduardacunha/Desktop/Projeto\ 2\ 5.42.57\ PM/Person.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"Person.d" -MT"Person.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Saves.o: /Users/eduardacunha/Desktop/Projeto\ 2\ 5.42.57\ PM/Saves.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"Saves.d" -MT"Saves.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Season.o: /Users/eduardacunha/Desktop/Projeto\ 2\ 5.42.57\ PM/Season.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"Season.d" -MT"Season.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TheVoice.o: /Users/eduardacunha/Desktop/Projeto\ 2\ 5.42.57\ PM/TheVoice.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"TheVoice.d" -MT"TheVoice.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.o: /Users/eduardacunha/Desktop/Projeto\ 2\ 5.42.57\ PM/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"main.d" -MT"main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


