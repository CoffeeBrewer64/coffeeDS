// https://problemkaputt.de/gbatek.htm#armcpuoverview

#ifndef ARM7_TYPES_H_INCLUDED
#define ARM7_TYPES_H_INCLUDED

#include <types/ndstypes.h>

// TODO: Make ARM9 registers
// TODO: Functions to copy data from one register type to another

// There's a total of 37 registers (32bit each), 31 general registers (Rxx) and 6 status registers (xPSR).
typedef struct
{
    uint32 r0;
    uint32 r1;
    uint32 r2;
    uint32 r3;
    uint32 r4;
    uint32 r5;
    uint32 r6;
    uint32 r7;
    uint32 r8;
    uint32 r9;
    uint32 r10;
    uint32 r11;
    uint32 r12;
    uint32 r13_SP; // SP = Stack Pointer
    uint32 r14_LR; // LR = Link Register
    uint32 r15_PC; // PC = Program Counter
    uint32 CPSR; // CPSR = Current Program Status Register
} arm7_registers_SysAndUser;

// FIQ = Fast Interrupt Request
typedef struct
{
    uint32 r0;
    uint32 r1;
    uint32 r2;
    uint32 r3;
    uint32 r4;
    uint32 r5;
    uint32 r6;
    uint32 r7;
    uint32 r8_fiq; // Banked
    uint32 r9_fiq; // Banked
    uint32 r10_fiq; // Banked
    uint32 r11_fiq; // Banked
    uint32 r12_fiq; // Banked
    uint32 r13_fiq; // Banked
    uint32 r14_fiq; // Banked
    uint32 r15;
    uint32 CPSR; // CPSR = Current Program Status Register
    uint32 SPSR_fiq; // Banked // SPSR = Suspended Program Status Register
} arm7_registers_FIQ;

typedef struct
{
    uint32 r0;
    uint32 r1;
    uint32 r2;
    uint32 r3;
    uint32 r4;
    uint32 r5;
    uint32 r6;
    uint32 r7;
    uint32 r8;
    uint32 r9;
    uint32 r10;
    uint32 r11;
    uint32 r12;
    uint32 r13_syc; // Banked
    uint32 r14_syc; // Banked
    uint32 r15;
    uint32 CPSR; // CPSR = Current Program Status Register
    uint32 SPSR_syc; // Banked // SPSR = Suspended Program Status Register
} arm7_registers_Supervisor;

typedef struct
{
    uint32 r0;
    uint32 r1;
    uint32 r2;
    uint32 r3;
    uint32 r4;
    uint32 r5;
    uint32 r6;
    uint32 r7;
    uint32 r8;
    uint32 r9;
    uint32 r10;
    uint32 r11;
    uint32 r12;
    uint32 r13_abt; // Banked
    uint32 r14_abt; // Banked
    uint32 r15;
    uint32 CPSR; // CPSR = Current Program Status Register
    uint32 SPSR_abt; // Banked // SPSR = Suspended Program Status Register
} arm7_registers_abort;

typedef struct
{
    uint32 r0;
    uint32 r1;
    uint32 r2;
    uint32 r3;
    uint32 r4;
    uint32 r5;
    uint32 r6;
    uint32 r7;
    uint32 r8;
    uint32 r9;
    uint32 r10;
    uint32 r11;
    uint32 r12;
    uint32 r13_irq; // Banked
    uint32 r14_irq; // Banked
    uint32 r15;
    uint32 CPSR; // CPSR = Current Program Status Register
    uint32 SPSR_irq; // Banked // SPSR = Suspended Program Status Register
} arm7_registers_IRQ;

typedef struct
{
    uint32 r0;
    uint32 r1;
    uint32 r2;
    uint32 r3;
    uint32 r4;
    uint32 r5;
    uint32 r6;
    uint32 r7;
    uint32 r8;
    uint32 r9;
    uint32 r10;
    uint32 r11;
    uint32 r12;
    uint32 r13_und; // Banked
    uint32 r14_und; // Banked
    uint32 r15;
    uint32 CPSR; // CPSR = Current Program Status Register
    uint32 SPSR_und; // Banked // SPSR = Suspended Program Status Register
} arm7_registers_Undefined;

typedef struct
{
    arm7_registers_abort abort_registers;
    arm7_registers_FIQ fiq_registers;
    arm7_registers_IRQ irq_registers;
    arm7_registers_Supervisor supervisor_registers;
    arm7_registers_SysAndUser SysAndUser_registers;
    arm7_registers_Undefined undefined_registers;
} arm7_registers_whole;

/*

Note that only some registers are 'banked', for example, each mode has it's own R14 register: called R14, R14_fiq, R14_svc, etc. for each mode respectively.
However, other registers are not banked, for example, each mode is using the same R0 register, so writing to R0 will always affect the content of R0 in other modes also.

R0-R12 Registers (General Purpose Registers)
These thirteen registers may be used for whatever general purposes. Basically, each is having same functionality and performance, ie. there is no 'fast accumulator' for arithmetic operations, and no 'special pointer register' for memory addressing.
However, in THUMB mode only R0-R7 (Lo registers) may be accessed freely, while R8-R12 and up (Hi registers) can be accessed only by some instructions.

R13 Register (SP)
This register is used as Stack Pointer (SP) in THUMB state. While in ARM state the user may decided to use R13 and/or other register(s) as stack pointer(s), or as general purpose register.
As shown in the table above, there's a separate R13 register in each mode, and (when used as SP) each exception handler may (and MUST!) use its own stack.

R14 Register (LR)
This register is used as Link Register (LR). That is, when calling to a sub-routine by a Branch with Link (BL) instruction, then the return address (ie. old value of PC) is saved in this register.
Storing the return address in the LR register is obviously faster than pushing it into memory, however, as there's only one LR register for each mode, the user must manually push its content before issuing 'nested' subroutines.
Same happens when an exception is called, PC is saved in LR of new mode.
Note: In ARM mode, R14 may be used as general purpose register also, provided that above usage as LR register isn't required.

R15 Register (PC)
R15 is always used as program counter (PC). Note that when reading R15, this will usually return a value of PC+nn because of read-ahead (pipelining), whereas 'nn' depends on the instruction and on the CPU state (ARM or THUMB).

CPSR and SPSR (Program Status Registers) (ARMv3 and up)
The current condition codes (flags) and CPU control bits are stored in the CPSR register. When an exception arises, the old CPSR is saved in the SPSR of the respective exception-mode (much like PC is saved in LR).

- GBATek

*/

#endif // ARM7_TYPES_H_INCLUDED
