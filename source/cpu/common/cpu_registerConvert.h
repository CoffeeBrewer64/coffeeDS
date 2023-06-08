/*
Name: cpu_registerConvert.h
Description: Header file for cpu_registerConvert.c
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#ifndef CPU_REGISTERCONVERT_H_INCLUDED
#define CPU_REGISTERCONVERT_H_INCLUDED

#include <types/arm7_types.h>

void cpu_registerConvert_arm7_wholeToWhole(arm7_registers_whole sharing, arm7_registers_whole receiving);

#endif // CPU_REGISTERCONVERT_H_INCLUDED
