#include <util/util_log.h>
#include <cart/cart_read.h>
#include <cpu/common/cpu_read.h>

int main()
{
    LOG("Started coffeeDS!");
    cartRead_init();
    cpu_read_init();
    return 0;
}
