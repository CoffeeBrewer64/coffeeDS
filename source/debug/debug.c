#include <cpu/common/cpu_read.h>
#include <util/util_log.h>
#include <stdio.h>
#include <types/ndstypes.h>

#include <debug/debug_opcodes.h>

// TODO: Dump to a separate file
// TODO: Option of whether or not to print only the opcode (in hex)
// TODO: Option of whether or not to print only the opcode (in a standard form)
void debug_dumpOpcodes()
{
    int repeat_times = 50000000; // TODO: Find a way to get the total number of opcodes in a whole ROM
    int x = 0;
    int grab_error_count = 0;
    int seek_error_count = 0;
    repeat_times = repeat_times + 1; // Goes through repeat_times - 1 times if this is NOT present
    while (x != repeat_times)
    {
        // TODO: Queue up all logging results to be written to a separate file later on
        // NOTE: using LOG instead of printf is bad for the disk's health
        uint32 y = cpu_read_arm_opcode(x);
        printf("Opcode with opcode index %i: (HEX) %X - (INT) %i\n",x, y, y);
        x++;
        if (x == repeat_times)
        {
            return;
        }
        if (y == -999)
        {
            // -999 is a special error code for this function as it unlikely to come up in a game's ROM
            printf("=====\nERROR WITH SEEKING: Opcode with opcode index %i: (HEX) %X - (INT) %i\n=====\n", x, y, y);
            seek_error_count = seek_error_count + 1;
        }
        if (y == -888)
        {
            // -888 is also a special error code, for the same reason as above ^
            printf("=====\nERROR WITH GRABBING: PROBABLY DOES NOT EXIST: Opcode with opcode index %i: (HEX) %X - (INT) %i\n=====\n", x, y, y);
            grab_error_count = grab_error_count + 1;
        }
        // TODO: Find a better way of seeing if the file has been fully scanned for opcodes
        if (grab_error_count >= 50 || seek_error_count >= 50)
        {
            LOG("Quitted opcode dumping: 50 grab errors OR 50 seek errors\n");
            return;
        }
    }
    return;
}
