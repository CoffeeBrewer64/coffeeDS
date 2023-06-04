#include <cpu/arm7/cpu_arm7_init.h>

int cpu_arm7_reset()
{
    current_arm7_registers.SysAndUser_registers.r15_PC = -1; // TODO: Make it VVVV0000h
    // TODO: Finish reset sequence (https://problemkaputt.de/gbatek.htm#armcpuoverview)
    return 1;
}
