/*
Name: cpu_arm7_init.h
Description: Header file for cpu_arm7_init.c
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#ifndef CPU_ARM7_INIT_H_INCLUDED
#define CPU_ARM7_INIT_H_INCLUDED

#include <types/arm7_types.h>

static arm7_registers_whole current_arm7_registers __attribute__((unused));

int cpu_arm7_init();

#endif // CPU_ARM7_INIT_H_INCLUDED
