#include <cpu/common/cpu_read.h>
#include <util/util_log.h>
#include <types/arm7_types.h>

// TODO: Init the ARM7 registers elsewhere (emuenv?)
arm7_registers_whole current_arm7_registers;

int cpu_init()
{
    LOG("Initialising CPU...");
    cpu_read_init();
    LOG("Initialised CPU!");
    return 1;
}
