/*
Name: cart_read.c
Description: File for reading data from the "cart" (cartridge, the .nds file)
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <types/ndstypes.h>
#include <util/util_log.h>
#include <cart/cart_read.h>

ndsrom_header current_header;

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

unsigned char* cart_read_gameTitle()
{
    return current_header.gameTitle;
}

unsigned char* cart_read_gameCode()
{
    return current_header.gameCode;
}

unsigned char* cart_read_makerCode()
{
    return current_header.makerCode;
}

unsigned char cart_read_unitCode()
{
    return current_header.unitCode;
}

unsigned char* cart_read_encryptionSeed()
{
    return current_header.encryptionSeed;
}

unsigned char cart_read_deviceCapacity()
{
    return current_header.deviceCapacity;
}

unsigned char* cart_read_reserved()
{
    return current_header.reserved;
}

unsigned char cart_read_romVersion()
{
    return current_header.romVersion;
}

unsigned char cart_read_internalFlags()
{
    return current_header.internalFlags;
}

unsigned int cart_read_arm9RomOffset()
{
    return current_header.arm9RomOffset;
}

unsigned int cart_read_arm9EntryAddress()
{
    return current_header.arm9EntryAddress;
}

unsigned int cart_read_arm9RamAddress()
{
    return current_header.arm9RamAddress;
}

unsigned int cart_read_arm9Size()
{
    return current_header.arm9Size;
}

unsigned int cart_read_arm7RomOffset()
{
    return current_header.arm7RomOffset;
}

unsigned int cart_read_arm7EntryAddress()
{
    return current_header.arm7EntryAddress;
}

unsigned int cart_read_arm7RamAddress()
{
    return current_header.arm7RamAddress;
}

unsigned int cart_read_arm7Size()
{
    return current_header.arm7Size;
}

unsigned int cart_read_fntOffset()
{
    return current_header.fntOffset;
}

unsigned int cart_read_fntSize()
{
    return current_header.fntSize;
}

unsigned int cart_read_fatOffset()
{
    return current_header.fatOffset;
}

unsigned int cart_read_fatSize()
{
    return current_header.fatSize;
}

unsigned int cart_read_arm9OverlayOffset()
{
    return current_header.arm9OverlayOffset;
}

unsigned int cart_read_arm9OverlaySize()
{
    return current_header.arm9OverlaySize;
}

unsigned int cart_read_arm7OverlayOffset()
{
    return current_header.arm7OverlayOffset;
}

unsigned int cart_read_arm7OverlaySize()
{
    return current_header.arm7OverlaySize;
}

unsigned short cart_read_normalCardControlRegSettings()
{
    return current_header.normalCardControlRegSettings;
}

unsigned short cart_read_secureCardControlRegSettings()
{
    return current_header.secureCardControlRegSettings;
}

unsigned int cart_read_iconTitleOffset()
{
    return current_header.iconTitleOffset;
}

unsigned short cart_read_secureAreaChecksum()
{
    return current_header.secureAreaChecksum;
}

unsigned short cart_read_secureAreaDelay()
{
    return current_header.secureAreaDelay;
}

unsigned int cart_read_arm9AutoLoadListRamAddress()
{
    return current_header.arm9AutoLoadListRamAddress;
}

unsigned int cart_read_arm7AutoLoadListRamAddress()
{
    return current_header.arm7AutoLoadListRamAddress;
}

unsigned short cart_read_secureAreaDisable()
{
    return current_header.secureAreaDisable;
}

unsigned short cart_read_ntrRegionRomSize()
{
    return current_header.ntrRegionRomSize;
}

unsigned short cart_read_ntrRegionRuntimeSize()
{
    return current_header.ntrRegionRuntimeSize;
}

unsigned int cart_read_totalRomSize()
{
    return current_header.totalRomSize;
}

unsigned short cart_read_romHeaderSize()
{
    return current_header.romHeaderSize;
}

unsigned short cart_read_reserved2()
{
    return current_header.reserved2;
}

unsigned short cart_read_logoChecksum()
{
    return current_header.logoChecksum;
}

unsigned short cart_read_headerChecksum()
{
    return current_header.headerChecksum;
}

unsigned int cart_read_arm9IconOffset()
{
    return current_header.arm9IconOffset;
}

unsigned int cart_read_arm9IconSize()
{
    return current_header.arm9IconSize;
}

unsigned int cart_read_arm7IconOffset()
{
    return current_header.arm7IconOffset;
}

unsigned int cart_read_arm7IconSize()
{
    return current_header.arm9IconSize;
}

unsigned int cart_read_titleLogoOffset()
{
    return current_header.titleLogoOffset;
}

unsigned int cart_read_titleLogoSize()
{
    return current_header.titleLogoSize;
}

unsigned int cart_read_secureAreaCrc()
{
    return current_header.secureAreaCrc;
}

unsigned int cart_read_saveType()
{
    return current_header.saveType;
}

unsigned int* cart_read_reserved3()
{
    return current_header.reserved3;
}

unsigned int cart_read_arm9LoadAddress()
{
    return current_header.arm9LoadAddress;
}

unsigned int cart_read_arm7LoadAddress()
{
    return current_header.arm7LoadAddress;
}

unsigned char* cart_read_reserved4()
{
    return current_header.reserved4;
}

unsigned short cart_read_region()
{
    return current_header.region;
}

unsigned char* cart_read_reserved5()
{
    return current_header.reserved5;
}

unsigned int cart_read_arm9OverlayJumpTableOffset()
{
    return current_header.arm9OverlayJumpTableOffset;
}

unsigned int cart_read_arm7OverlayJumpTableOffset()
{
    return current_header.arm7OverlayJumpTableOffset;
}

unsigned int* cart_read_reserved6()
{
    return current_header.reserved6;
}

unsigned int cart_read_bannerOffset()
{
    return current_header.bannerOffset;
}

unsigned char* cart_read_reserved7()
{
    return current_header.reserved7;
}

unsigned int cart_read_secureTransferTimeout()
{
    return current_header.secureTransferTimeout;
}

unsigned int cart_read_arm9AutoloadListRamAddressEnd()
{
    return current_header.arm9AutoloadListRamAddressEnd;
}

unsigned int cart_read_arm7AutoloadListRamAddressEnd()
{
    return current_header.arm7AutoloadListRamAddressEnd;
}

unsigned char* cart_read_reserved8()
{
    return current_header.reserved8;
}

unsigned char cart_read_ntrRegionRomVersion()
{
    return current_header.ntrRegionRomVersion;
}

unsigned char* cart_read_reserved9()
{
    return current_header.reserved9;
}

unsigned int cart_read_defaultTiming()
{
    return current_header.defaultTiming;
}

unsigned int cart_read_arm9AutoloadListRamAddressMain()
{
    return current_header.arm9AutoloadListRamAddressMain;
}

unsigned int cart_read_arm7AutoloadListRamAddressMain()
{
    return current_header.arm7AutoloadListRamAddressMain;
}

unsigned int* cart_read_reserved10()
{
    return current_header.reserved10;
}

unsigned int cart_read_filenameTableOffset()
{
    return current_header.filenameTableOffset;
}

unsigned int cart_read_filenameTableSize()
{
    return current_header.filenameTableSize;
}

unsigned int cart_read_fileAllocationTableOffset()
{
    return current_header.fileAllocationTableOffset;
}

unsigned int cart_read_fileAllocationTableSize()
{
    return current_header.fileAllocationTableSize;
}

unsigned int cart_read_filenameTable2Offset()
{
    return current_header.filenameTable2Offset;
}

unsigned int cart_read_filenameTable2Size()
{
    return current_header.filenameTable2Size;
}

unsigned int cart_read_fileAllocationTable2Offset()
{
    return current_header.fileAllocationTable2Offset;
}

unsigned int cart_read_fileAllocationTable2Size()
{
    return current_header.fileAllocationTable2Size;
}

unsigned int cart_read_bannerAnimationOffset()
{
    return current_header.bannerAnimationOffset;
}

unsigned int* cart_read_reserved11()
{
    return current_header.reserved11;
}

unsigned char cart_read_ndsRegion()
{
    return current_header.ndsRegion;
}

unsigned char* cart_read_reserved12()
{
    return current_header.reserved12;
}
