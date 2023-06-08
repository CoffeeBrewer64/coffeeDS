/*
Name: cpu_read.c
Description: Functions for reading the .nds instructions
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

// Conversion to be dealt with in cpu_convert.c/.h

#include <util/util_log.h>
#include <types/ndstypes.h>
#include <stdio.h>
#include <cpu/common/cpu_read.h>
#include <types/arm7_types.h>
#include <cpu/arm7/cpu_arm7_init.h>

FILE* game_file;
bool isInit = false;

// Called at cpu_init()
int cpu_read_init()
{
    LOG("Starting CPU...");
    game_file = fopen("game.nds", "rb");
    if (game_file == NULL)
    {
        LOG("Could not init CPU read: game.nds does not exist/could not be found");
        return -1;
    }
    fclose(game_file);
    LOG("Started CPU read!");
    isInit = true;
    return 1;
}

// TODO: Properly extract opcodes
// TODO: Verify THUMB opcodes against a pre-existing list of all known opcodes (or, when opcodes are being executed, examine the opcode which failed because it is not an implemented opcode)

// Will read (and return) whatever opcode is at the provided opcode index
// Done as THUMB mode
// TODO: Spot 32 bit instructions and skip over them
// TODO: Call out 32 bit instructions
// TODO: Skip over the ROM header
// TODO: Account for instruction arguments
uint16 cpu_read_thumb_opcode(uint16 opcodeIndex)
{
    uint16 opcode;
    game_file = fopen("game.nds", "rb");
    // Calculate the offset in the game_file based on the opcode index
    size_t offset = opcodeIndex * sizeof(uint16);

    // Seek to the specified opcode position
    if (fseek(game_file, offset, SEEK_SET) != 0)
    {
        LOG("Error seeking to opcode index %u in game.nds\n", opcodeIndex);
        fclose(game_file);
        return -999; // Special error code; unlikely to be found in a game's ROM
    }

    // Read the opcode
    size_t bytesRead = fread(&opcode, sizeof(uint16), 1, game_file);

    if (bytesRead != 1)
    {
        LOG("Error reading opcode from game.nds\n");
        fclose(game_file);
        return -888; // Special error code; unlikely to be found in a game's ROM
    }
    fclose(game_file);
    return opcode;
}

// TODO: Account for instruction arguments
// TODO: Skip over the ROM header
uint32 cpu_read_arm_opcode(uint32 opcodeIndex)
{
    uint32 opcode;
    game_file = fopen("game.nds", "rb");
    // Calculate the offset in the game_file based on the opcode index
    size_t offset = opcodeIndex * sizeof(uint32);

    // Seek to the specified opcode position
    if (fseek(game_file, offset, SEEK_SET) != 0)
    {
        LOG("Error seeking to opcode index %u in game.nds\n", opcodeIndex);
        fclose(game_file);
        return -999; // Special error code; unlikely to be found in a game's ROM
    }

    // Read the opcode
    size_t bytesRead = fread(&opcode, sizeof(uint32), 1, game_file);

    if (bytesRead != 1)
    {
        LOG("Error reading opcode from game.nds\n");
        fclose(game_file);
        return -888; // Special error code; unlikely to be found in a game's ROM
    }
    fclose(game_file);
    return opcode;
}

arm7_registers_whole cpu_read_arm7_registers_whole()
{
    arm7_registers_whole _new;
    _new = current_arm7_registers;
    return _new;
}
