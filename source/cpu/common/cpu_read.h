#ifndef CPU_READ_H_INCLUDED
#define CPU_READ_H_INCLUDED

#include <types/ndstypes.h>

int cpu_read_init();
uint16 cpu_read_thumb_opcode(uint16 opcodeIndex);
uint32 cpu_read_arm_opcode(uint32 opcodeIndex);

#endif // CPU_READ_H_INCLUDED
