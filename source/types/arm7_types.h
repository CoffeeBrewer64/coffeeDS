// https://problemkaputt.de/gbatek.htm#armcpuoverview

#ifndef ARM7_TYPES_H_INCLUDED
#define ARM7_TYPES_H_INCLUDED

#include <types/ndstypes.h>

typedef struct
{
    int16  PC;
    int16  ADDR;
    int16  r0;
    int16  r1;
    int16  r2;
    int16  r3;
    int16  r4;
    int16  r5;
    int16  r6;
    int16  r7;
    int16  r8;
    int16  r9;
    int16  r10;
    int16  r11;
    int16  r12;
    int16  sp;
    int16  lr;
    int16  pc;
} arm7_registers;

#endif // ARM7_TYPES_H_INCLUDED
