/*
Name: cpu_registerConvert.c
Description: Converting registers
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#include <types/arm7_types.h>
#include <util/util_log.h>
#include <cpu/common/cpu_registerConvert.h>

void cpu_registerConvert_arm7_wholeToWhole(arm7_registers_whole sharing, arm7_registers_whole receiving)
{
    LOG("Converting whole ARM7 register from other whole ARM7 register...");
    // Instead of doing `receiving = sharing;`, we separate them into parts because doing it whole may not work correctly.
    // TODO: Check if the above is trues
    receiving.abort_registers = sharing.abort_registers;
    receiving.fiq_registers = sharing.fiq_registers;
    receiving.irq_registers = sharing.irq_registers;
    receiving.supervisor_registers = sharing.supervisor_registers;
    receiving.SysAndUser_registers = sharing.SysAndUser_registers;
    receiving.undefined_registers = sharing.undefined_registers;
    LOG("Converted whole ARM7 register from other whole ARM7 register!");
}
