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

unsigned int cartRead_get_arm9IconOffset()
{
    return current_header.arm9IconOffset;
}

unsigned int cartRead_get_arm9IconSize()
{
    return current_header.arm9IconSize;
}

unsigned int cartRead_get_arm7IconOffset()
{
    return current_header.arm7IconOffset;
}

unsigned int cartRead_get_arm7IconSize()
{
    return current_header.arm9IconSize;
}

unsigned int cartRead_get_titleLogoOffset()
{
    return current_header.titleLogoOffset;
}

unsigned int cartRead_get_titleLogoSize()
{
    return current_header.titleLogoSize;
}

unsigned int cartRead_get_secureAreaCrc()
{
    return current_header.secureAreaCrc;
}

unsigned int cartRead_get_romSize()
{
    return current_header.romSize;
}

unsigned int cartRead_get_saveType()
{
    return current_header.saveType;
}

unsigned int* cartRead_get_reserved3()
{
    return current_header.reserved3;
}

unsigned int cartRead_get_arm9LoadAddress()
{
    return current_header.arm9LoadAddress;
}

unsigned int cartRead_get_arm7LoadAddress()
{
    return current_header.arm7LoadAddress;
}

unsigned char* cartRead_get_reserved4()
{
    return current_header.reserved4;
}

unsigned short cartRead_get_region()
{
    return current_header.region;
}

unsigned char* cartRead_get_reserved5()
{
    return current_header.reserved5;
}

unsigned int cartRead_get_arm9OverlayJumpTableOffset()
{
    return current_header.arm9OverlayJumpTableOffset;
}

unsigned int cartRead_get_arm7OverlayJumpTableOffset()
{
    return current_header.arm7OverlayJumpTableOffset;
}

unsigned int* cartRead_get_reserved6()
{
    return current_header.reserved6;
}

unsigned int cartRead_get_bannerOffset()
{
    return current_header.bannerOffset;
}

unsigned char* cartRead_get_reserved7()
{
    return current_header.reserved7;
}

unsigned int cartRead_get_secureTransferTimeout()
{
    return current_header.secureTransferTimeout;
}

unsigned int cartRead_get_arm9AutoloadListRamAddressEnd()
{
    return current_header.arm9AutoloadListRamAddressEnd;
}

unsigned int cartRead_get_arm7AutoloadListRamAddressEnd()
{
    return current_header.arm7AutoloadListRamAddressEnd;
}

unsigned char* cartRead_get_reserved8()
{
    return current_header.reserved8;
}

unsigned char cartRead_get_ntrRegionRomVersion()
{
    return current_header.ntrRegionRomVersion;
}

unsigned char* cartRead_get_reserved9()
{
    return current_header.reserved9;
}

unsigned int cartRead_get_defaultTiming()
{
    return current_header.defaultTiming;
}

unsigned int cartRead_get_arm9AutoloadListRamAddressMain()
{
    return current_header.arm9AutoloadListRamAddressMain;
}

unsigned int cartRead_get_arm7AutoloadListRamAddressMain()
{
    return current_header.arm7AutoloadListRamAddressMain;
}

unsigned int* cartRead_get_reserved10()
{
    return current_header.reserved10;
}

unsigned int cartRead_get_filenameTableOffset()
{
    return current_header.filenameTableOffset;
}

unsigned int cartRead_get_filenameTableSize()
{
    return current_header.filenameTableSize;
}

unsigned int cartRead_get_fileAllocationTableOffset()
{
    return current_header.fileAllocationTableOffset;
}

unsigned int cartRead_get_fileAllocationTableSize()
{
    return current_header.fileAllocationTableSize;
}

unsigned int cartRead_get_filenameTable2Offset()
{
    return current_header.filenameTable2Offset;
}

unsigned int cartRead_get_filenameTable2Size()
{
    return current_header.filenameTable2Size;
}

unsigned int cartRead_get_fileAllocationTable2Offset()
{
    return current_header.fileAllocationTable2Offset;
}

unsigned int cartRead_get_fileAllocationTable2Size()
{
    return current_header.fileAllocationTable2Size;
}

unsigned int cartRead_get_bannerAnimationOffset()
{
    return current_header.bannerAnimationOffset;
}

unsigned int* cartRead_get_reserved11()
{
    return current_header.reserved11;
}

unsigned char cartRead_get_ndsRegion()
{
    return current_header.ndsRegion;
}

unsigned char* cartRead_get_reserved12()
{
    return current_header.reserved12;
}
