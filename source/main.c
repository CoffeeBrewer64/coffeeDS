#include <util/util_log.h>
#include <cart/cart_read.h>
#include <cpu/cpu.h>

int main()
{
    LOG("Started coffeeDS!");
    cpu_init();
    cartRead_init();
    LOG("Ended coffeeDS!");
    return 0;
}
