#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <types/ndstypes.h>
#include <util/util_log.h>
#include <cart/cart_read.h>

int cartRead_init()
{
    LOG("Starting cartRead...");
    FILE* file = fopen("game.nds", "rb");
    if (file == NULL)
    {
        LOG("Could not init cart reading: game.nds does not exist/could not be found");
        return -1;
    }

    if (fread(&current_header, sizeof(ndsrom_header), 1, file) != 1)
    {
        LOG("Failed to read the NDS ROM header.");
        fclose(file);
        return -1;
    }
    LOG("Started cartRead!");
    return 1;
}

unsigned char* cartRead_get_gameTitle()
{
    return current_header.gameTitle;
}

unsigned char* cartRead_get_gameCode()
{
    return current_header.gameCode;
}

unsigned char* cartRead_get_makerCode()
{
    return current_header.makerCode;
}

unsigned char cartRead_get_unitCode()
{
    return current_header.unitCode;
}

unsigned char* cartRead_get_encryptionSeed()
{
    return current_header.encryptionSeed;
}

unsigned char cartRead_get_deviceCapacity()
{
    return current_header.deviceCapacity;
}

unsigned char* cartRead_get_reserved()
{
    return current_header.reserved;
}

unsigned char cartRead_get_romVersion()
{
    return current_header.romVersion;
}

unsigned char cartRead_get_internalFlags()
{
    return current_header.internalFlags;
}

unsigned int cartRead_get_arm9RomOffset()
{
    return current_header.arm9RomOffset;
}

unsigned int cartRead_get_arm9EntryAddress()
{
    return current_header.arm9EntryAddress;
}

unsigned int cartRead_get_arm9RamAddress()
{
    return current_header.arm9RamAddress;
}

unsigned int cartRead_get_arm9Size()
{
    return current_header.arm9Size;
}

unsigned int cartRead_get_arm7RomOffset()
{
    return current_header.arm7RomOffset;
}

unsigned int cartRead_get_arm7EntryAddress()
{
    return current_header.arm7EntryAddress;
}

unsigned int cartRead_get_arm7RamAddress()
{
    return current_header.arm7RamAddress;
}

unsigned int cartRead_get_arm7Size()
{
   return current_header.arm7Size;
}

unsigned int cartRead_get_fntOffset()
{
    return current_header.fntOffset;
}

unsigned int cartRead_get_fntSize()
{
    return current_header.fntSize;
}

unsigned int cartRead_get_fatOffset()
{
    return current_header.fatOffset;
}

unsigned int cartRead_get_fatSize()
{
    return current_header.fatSize;
}

unsigned int cartRead_get_arm9OverlayOffset()
{
    return current_header.arm9OverlayOffset;
}

unsigned int cartRead_get_arm9OverlaySize()
{
    return current_header.arm9OverlaySize;
}

unsigned int cartRead_get_arm7OverlayOffset()
{
    return current_header.arm7OverlayOffset;
}

unsigned int cartRead_get_arm7OverlaySize()
{
    return current_header.arm7OverlaySize;
}

unsigned short cartRead_get_normalCardControlRegSettings()
{
    return current_header.normalCardControlRegSettings;
}

unsigned short cartRead_get_secureCardControlRegSettings()
{
    return current_header.secureCardControlRegSettings;
}

unsigned int cartRead_get_iconTitleOffset()
{
    return current_header.iconTitleOffset;
}

unsigned short cartRead_get_secureAreaChecksum()
{
    return current_header.secureAreaChecksum;
}

unsigned short cartRead_get_secureAreaDelay()
{
    return current_header.secureAreaDelay;
}

unsigned int cartRead_get_arm9AutoLoadListRamAddress()
{
    return current_header.arm9AutoLoadListRamAddress;
}

unsigned int cartRead_get_arm7AutoLoadListRamAddress()
{
    return current_header.arm7AutoLoadListRamAddress;
}

unsigned short cartRead_get_secureAreaDisable()
{
    return current_header.secureAreaDisable;
}

unsigned short cartRead_get_ntrRegionRomSize()
{
    return current_header.ntrRegionRomSize;
}

unsigned short cartRead_get_ntrRegionRuntimeSize()
{
    return current_header.ntrRegionRuntimeSize;
}

unsigned int cartRead_get_totalRomSize()
{
    return current_header.totalRomSize;
}

unsigned short cartRead_get_romHeaderSize()
{
    return current_header.romHeaderSize;
}

unsigned short cartRead_get_reserved2()
{
    return current_header.reserved2;
}

unsigned short cartRead_get_logoChecksum()
{
    return current_header.logoChecksum;
}

unsigned short cartRead_get_headerChecksum()
{
    return current_header.headerChecksum;
}
