/*
Name: bios.c
Description: Operates the BIOS instructions
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

// Please see https://problemkaputt.de/gbatek.htm#biosfunctionsummary

#include <cpu/arm7/cpu_arm7_init.h>
#include <bios/bios_funcs.h>

#include <bios/bios.h>

// TODO: Add bios_onUpdate_arm9
// TODO: Add bios_onUpdate_gba
// TODO: Add bios_onUpdate_dsi7
// TODO: Add bios_onUpdate_dsi9

int bios_onUpdate_arm7()
{
    // FIXME: Find a better way of dealing with all of these registers
    switch (current_arm7_registers.SysAndUser_registers.r0)
    {
        /// Valid
        case 0x00:
        // Soft reset
        case 0x06:
        // Halt
        case 0x07:
        // Stop/Sleep
        case 0x04:
        // IntrWait
        case 0x05:
        // VBlankIntrWait
        case 0x09:
        // Div
        case 0x0D:
        // Sqrt
        case 0x0B:
        // CpuSet
        case 0x0C:
        // CpuFastSet
        case 0x10:
        // BitUnPack
        case 0x11:
        // LZ77UnCompReadNormalWrite8bit
        // (WRam)
        case 0x12:
        // LZ77UnCompReadByCallbackWrite16bit
        case 0x13:
        // HuffUnCompReadByCallback
        case 0x14:
        // RLUnCompReadNormalWrite8bit
        case 0x15:
        // RLUnCompReadByCallbackWrite16bit
        case 0x08:
        // SoundBias
        case 0x1F:
        // CustomHalt
        case 0x03:
        // WaitByLoop
        case 0x0E:
        // GetCRC16
        case 0x0F:
        // IsDebugger
        // TODO: IsDebugger (0x0F)
        case 0x1A:
        // GetSineTable
        case 0x1B:
        // GetPitchTable
        case 0x1C:
        // GetVolumeTable
        case 0x1D:
        // GetBootProcs
        case 0x20:
            bios_funcs_arm7_crash();
        /// Invalid
        case 0x01:
            bios_funcs_arm7_invalid();
        case 0x02:
            bios_funcs_arm7_invalid();
        case 0x0A:
            bios_funcs_arm7_invalid();
        case 0x16:
            bios_funcs_arm7_invalid();
        case 0x17:
            bios_funcs_arm7_invalid();
        case 0x18:
            bios_funcs_arm7_invalid();
        case 0x19:
            bios_funcs_arm7_invalid();
        case 0x1E:
            bios_funcs_arm7_invalid();
    }
    if (current_arm7_registers.SysAndUser_registers.r0 > 0x20)
    {
        bios_funcs_arm7_crash();
    }

    switch (current_arm7_registers.SysAndUser_registers.r1)
    {
        /// Valid
        case 0x00:
        // Soft reset
        case 0x06:
        // Halt
        case 0x07:
        // Stop/Sleep
        case 0x04:
        // IntrWait
        case 0x05:
        // VBlankIntrWait
        case 0x09:
        // Div
        case 0x0D:
        // Sqrt
        case 0x0B:
        // CpuSet
        case 0x0C:
        // CpuFastSet
        case 0x10:
        // BitUnPack
        case 0x11:
        // LZ77UnCompReadNormalWrite8bit
        // (WRam)
        case 0x12:
        // LZ77UnCompReadByCallbackWrite16bit
        case 0x13:
        // HuffUnCompReadByCallback
        case 0x14:
        // RLUnCompReadNormalWrite8bit
        case 0x15:
        // RLUnCompReadByCallbackWrite16bit
        case 0x08:
        // SoundBias
        case 0x1F:
        // CustomHalt
        case 0x03:
        // WaitByLoop
        case 0x0E:
        // GetCRC16
        case 0x0F:
        // IsDebugger
        // TODO: IsDebugger (0x0F)
        case 0x1A:
        // GetSineTable
        case 0x1B:
        // GetPitchTable
        case 0x1C:
        // GetVolumeTable
        case 0x1D:
        // GetBootProcs
        case 0x20:
            bios_funcs_arm7_crash();
        /// Invalid
        case 0x01:
            bios_funcs_arm7_invalid();
        case 0x02:
            bios_funcs_arm7_invalid();
        case 0x0A:
            bios_funcs_arm7_invalid();
        case 0x16:
            bios_funcs_arm7_invalid();
        case 0x17:
            bios_funcs_arm7_invalid();
        case 0x18:
            bios_funcs_arm7_invalid();
        case 0x19:
            bios_funcs_arm7_invalid();
        case 0x1E:
            bios_funcs_arm7_invalid();
    }
    if (current_arm7_registers.SysAndUser_registers.r1 > 0x20)
    {
        bios_funcs_arm7_crash();
    }

    switch (current_arm7_registers.SysAndUser_registers.r2)
    {
        /// Valid
        case 0x00:
        // Soft reset
        case 0x06:
        // Halt
        case 0x07:
        // Stop/Sleep
        case 0x04:
        // IntrWait
        case 0x05:
        // VBlankIntrWait
        case 0x09:
        // Div
        case 0x0D:
        // Sqrt
        case 0x0B:
        // CpuSet
        case 0x0C:
        // CpuFastSet
        case 0x10:
        // BitUnPack
        case 0x11:
        // LZ77UnCompReadNormalWrite8bit
        // (WRam)
        case 0x12:
        // LZ77UnCompReadByCallbackWrite16bit
        case 0x13:
        // HuffUnCompReadByCallback
        case 0x14:
        // RLUnCompReadNormalWrite8bit
        case 0x15:
        // RLUnCompReadByCallbackWrite16bit
        case 0x08:
        // SoundBias
        case 0x1F:
        // CustomHalt
        case 0x03:
        // WaitByLoop
        case 0x0E:
        // GetCRC16
        case 0x0F:
        // IsDebugger
        // TODO: IsDebugger (0x0F)
        case 0x1A:
        // GetSineTable
        case 0x1B:
        // GetPitchTable
        case 0x1C:
        // GetVolumeTable
        case 0x1D:
        // GetBootProcs
        case 0x20:
            bios_funcs_arm7_crash();
        /// Invalid
        case 0x01:
            bios_funcs_arm7_invalid();
        case 0x02:
            bios_funcs_arm7_invalid();
        case 0x0A:
            bios_funcs_arm7_invalid();
        case 0x16:
            bios_funcs_arm7_invalid();
        case 0x17:
            bios_funcs_arm7_invalid();
        case 0x18:
            bios_funcs_arm7_invalid();
        case 0x19:
            bios_funcs_arm7_invalid();
        case 0x1E:
            bios_funcs_arm7_invalid();
    }
    if (current_arm7_registers.SysAndUser_registers.r2 > 0x20)
    {
        bios_funcs_arm7_crash();
    }

    switch (current_arm7_registers.SysAndUser_registers.r3)
    {
        /// Valid
        case 0x00:
        // Soft reset
        case 0x06:
        // Halt
        case 0x07:
        // Stop/Sleep
        case 0x04:
        // IntrWait
        case 0x05:
        // VBlankIntrWait
        case 0x09:
        // Div
        case 0x0D:
        // Sqrt
        case 0x0B:
        // CpuSet
        case 0x0C:
        // CpuFastSet
        case 0x10:
        // BitUnPack
        case 0x11:
        // LZ77UnCompReadNormalWrite8bit
        // (WRam)
        case 0x12:
        // LZ77UnCompReadByCallbackWrite16bit
        case 0x13:
        // HuffUnCompReadByCallback
        case 0x14:
        // RLUnCompReadNormalWrite8bit
        case 0x15:
        // RLUnCompReadByCallbackWrite16bit
        case 0x08:
        // SoundBias
        case 0x1F:
        // CustomHalt
        case 0x03:
        // WaitByLoop
        case 0x0E:
        // GetCRC16
        case 0x0F:
        // IsDebugger
        // TODO: IsDebugger (0x0F)
        case 0x1A:
        // GetSineTable
        case 0x1B:
        // GetPitchTable
        case 0x1C:
        // GetVolumeTable
        case 0x1D:
        // GetBootProcs
        case 0x20:
            bios_funcs_arm7_crash();
        /// Invalid
        case 0x01:
            bios_funcs_arm7_invalid();
        case 0x02:
            bios_funcs_arm7_invalid();
        case 0x0A:
            bios_funcs_arm7_invalid();
        case 0x16:
            bios_funcs_arm7_invalid();
        case 0x17:
            bios_funcs_arm7_invalid();
        case 0x18:
            bios_funcs_arm7_invalid();
        case 0x19:
            bios_funcs_arm7_invalid();
        case 0x1E:
            bios_funcs_arm7_invalid();
    }
    if (current_arm7_registers.SysAndUser_registers.r3 > 0x20)
    {
        bios_funcs_arm7_crash();
    }

    return 0;
}
