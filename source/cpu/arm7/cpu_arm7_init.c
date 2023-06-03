#include <types/arm7_types.h>
#include <types/ndstypes.h>

#include <cpu/arm7/cpu_arm7_init.h>

arm7_registers_whole current_arm7_registers;

int cpu_arm7_init()
{
    current_arm7_registers.abort_registers.r0 = 0; // Just a lil' value to make sure it works
    return 1;
}
