#include <cpu/common/cpu_read.h>
#include <util/util_log.h>

int cpu_init()
{
    LOG("Initialising CPU...");
    cpu_read_init();
    LOG("Initialised CPU!");
    return 1;
}
