/*
Name: cpu_arm7_init.c
Description: Initializing the ARM7TDMI-S CPU emulator
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#include <types/arm7_types.h>
#include <types/ndstypes.h>

#include <cpu/arm7/cpu_arm7_init.h>

int cpu_arm7_init()
{
    current_arm7_registers.abort_registers.r0 = 0; // Just a lil' value to make sure it works
    return 1;
}
