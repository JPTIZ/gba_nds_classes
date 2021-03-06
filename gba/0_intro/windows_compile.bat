@echo off
set path=%path%;C:\devkitPro\devkitARM\bin\;
arm-none-eabi-g++ -g -Wall -O3 -mcpu=arm7tdmi -mtune=arm7tdmi -fomit-frame-pointer -ffast-math -mthumb -mthumb-interwork -fno-rtti -fno-exceptions --std=c++14 -c source/main.cpp -o build/main.o
arm-none-eabi-g++ -specs=gba.specs -mthumb -mthumb-interwork build/main.o -o main.elf
arm-none-eabi-objcopy -O binary main.elf main.gba
gbafix main.gba
