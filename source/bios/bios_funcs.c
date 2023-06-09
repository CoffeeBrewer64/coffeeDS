/*
Name: bios_funcs.c
Description: Defines the BIOS functions
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#include <cpu/arm7/cpu_arm7_init.h>

#include <util/util_log.h>

void bios_funcs_arm7_invalid()
{
    LOG("ARM7 BIOS: Invalid BIOS function call (from the ROM)");
    return;
}

void bios_funcs_arm7_crash()
{
    current_arm7_registers.SysAndUser_registers.r15_PC = -1;
    // NOTE: This is not a permanent solution, it works right now because, in the main loop, this value on this register will cause a crash
    // However, that is an alternative for the resetting system, so both will have to be done at some point (both are already todoed)
    return;
}
