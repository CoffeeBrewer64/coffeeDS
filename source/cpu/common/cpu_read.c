// Functions for reading the .nds instructions
// Conversion to be dealt with in cpu_convert.c/.h

#include <util/util_log.h>
#include <types/ndstypes.h>
#include <stdio.h>
#include <cpu/common/cpu_read.h>

FILE* game_file;
bool isInit = false;

// Call at cpu_init()
// TODO: Add cpu_init()
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

uint16 cpu_read_arm7_opcode(uint16 opcodeIndex)
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
        return opcode;
    }

    // Read the opcode
    size_t bytesRead = fread(&opcode, sizeof(uint16), 1, game_file);

    if (bytesRead != 1)
    {
        LOG("Error reading opcode from game.nds\n");
        fclose(game_file);
        return opcode;
    }
    fclose(game_file);
    return opcode;
}

// TODO: More general cpu_read_opcode

uint32 cpu_read_arm9_opcode(uint32 opcodeIndex)
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
        return opcode;
    }

    // Read the opcode
    size_t bytesRead = fread(&opcode, sizeof(uint32), 1, game_file);

    if (bytesRead != 1)
    {
        LOG("Error reading opcode from game.nds\n");
        fclose(game_file);
        return opcode;
    }
    fclose(game_file);
    return opcode;
}
