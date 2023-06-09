/*
Name: cpu.c
Description: Main CPU source file
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#include <cpu/common/cpu_read.h>
#include <cpu/arm7/cpu_arm7_init.h>
#include <util/util_log.h>
#include <types/arm7_types.h>

int cpu_init()
{
    LOG("Initialising CPU...");
    cpu_arm7_init();
    cpu_read_init();
    LOG("Initialised CPU!");
    return 0;
}
