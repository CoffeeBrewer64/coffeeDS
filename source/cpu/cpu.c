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
    return 1;
}
