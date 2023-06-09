/*
Name: debug.c
Description: Source file for ALL debugging
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#include <stdio.h>

#include <cpu/common/cpu_read.h>
#include <util/util_log.h>
#include <types/ndstypes.h>
#include <emuenv/emuenv.h>

#include <debug/debug_opcodes.h>
#include <debug/debug_cart.h>

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
        printf("Opcode with opcode index %i: (HEX) %X - (INT) %i\n", x, y, y);
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

// TODO: Dump into own file
void debug_dumpNdsHeader()
{

    printf("=====\nNDS HEADER DUMP for game with title \"%s\":\n", emuenv_currentHeader.gameTitle);
    printf("Game title: %s\n", emuenv_currentHeader.gameTitle);
    printf("Game code: %s\n", emuenv_currentHeader.gameCode);
    printf("Maker code: %s\n", emuenv_currentHeader.makerCode);
    printf("Unit code: %i\n", emuenv_currentHeader.unitCode);
    printf("Encryption seed: %s\n", emuenv_currentHeader.encryptionSeed);
    printf("Device capacity: %i\n", emuenv_currentHeader.deviceCapacity);
    printf("Reserved 1: %s\n", emuenv_currentHeader.reserved);
    printf("ROM version: %i\n", emuenv_currentHeader.romVersion);
    printf("Internal flags: %i\n", emuenv_currentHeader.internalFlags);
    printf("ARM9 ROM Offset: %i\n", emuenv_currentHeader.arm9RomOffset);
    printf("ARM9 ROM Offset (HEX): 0x%X\n", emuenv_currentHeader.arm9RomOffset);
    printf("ARM9 Entry Address: %i\n", emuenv_currentHeader.arm9EntryAddress);
    printf("ARM9 Entry Address (HEX): 0x%X\n", emuenv_currentHeader.arm9EntryAddress);
    printf("ARM9 RAM Address: %i\n", emuenv_currentHeader.arm9RamAddress);
    printf("ARM9 RAM Address (HEX): 0x%X\n", emuenv_currentHeader.arm9RamAddress);
    printf("ARM9 Size: %i\n", emuenv_currentHeader.arm9Size);
    printf("ARM9 Size (HEX): 0x%X\n", emuenv_currentHeader.arm9Size);
    printf("ARM7 ROM Offset: %i\n", emuenv_currentHeader.arm7RomOffset);
    printf("ARM7 ROM Offset (HEX): 0x%X\n", emuenv_currentHeader.arm7RomOffset);
    printf("ARM7 Entry Address: %i\n", emuenv_currentHeader.arm7EntryAddress);
    printf("ARM7 Entry Address (HEX): 0x%X\n", emuenv_currentHeader.arm7EntryAddress);
    printf("ARM7 RAM Address: %i\n", emuenv_currentHeader.arm7RamAddress);
    printf("ARM7 RAM Address (HEX): 0x%X\n", emuenv_currentHeader.arm7RamAddress);
    printf("ARM7 Size: %i\n", emuenv_currentHeader.arm7Size);
    printf("ARM7 Size (HEX): 0x%X\n", emuenv_currentHeader.arm7Size);
    printf("fnt offset: %i\n", emuenv_currentHeader.fntOffset);
    printf("fnt offset (HEX): 0x%X\n", emuenv_currentHeader.fntSize);
    printf("fat offset: %i\n", emuenv_currentHeader.fatOffset);
    printf("fat offset (HEX): 0x%X\n", emuenv_currentHeader.fatOffset);
    printf("fat size: %i\n", emuenv_currentHeader.fatSize);
    printf("fat size (HEX): 0x%X\n", emuenv_currentHeader.fatSize);
    printf("ARM9 Overlay Offset: %i\n", emuenv_currentHeader.arm9OverlayOffset);
    printf("ARM9 Overlay Offset (HEX): 0x%X\n", emuenv_currentHeader.arm9OverlayOffset);
    printf("ARM9 Overlay Size: %i\n", emuenv_currentHeader.arm9OverlaySize);
    printf("ARM9 Overlay Size (HEX): 0x%X\n", emuenv_currentHeader.arm9OverlaySize);
    printf("ARM7 Overlay Size: %i\n", emuenv_currentHeader.arm7OverlaySize);
    printf("ARM7 Overlay Size (HEX): 0x%X\n", emuenv_currentHeader.arm7OverlaySize);
    printf("Normal Card Control Reg(ister?) Settings: %i\n", emuenv_currentHeader.normalCardControlRegSettings);
    printf("Normal Card Control Reg(ister?) Settings (HEX): 0x%X\n", emuenv_currentHeader.normalCardControlRegSettings);
    printf("Secure Card Control Reg(ister?) Settings: %i\n", emuenv_currentHeader.secureCardControlRegSettings);
    printf("Secure Card Control Reg(ister?) Settings (HEX): 0x%X\n", emuenv_currentHeader.secureCardControlRegSettings);
    printf("Icon Title Offset: %i\n", emuenv_currentHeader.iconTitleOffset);
    printf("Icon Title Offset (HEX): 0x%X\n", emuenv_currentHeader.iconTitleOffset);
    printf("Secure Area Checksum: %i\n", emuenv_currentHeader.secureAreaChecksum);
    printf("Secure Area Checksum (HEX): 0x%X\n", emuenv_currentHeader.secureAreaChecksum);
    printf("Secure Area Delay: %i\n", emuenv_currentHeader.secureAreaDelay);
    printf("Secure Area Delay (HEX): 0x%X\n", emuenv_currentHeader.secureAreaDelay);
    printf("ARM9 Auto Load List RAM Address: %i\n", emuenv_currentHeader.arm9AutoLoadListRamAddress);
    printf("ARM9 Auto Load List RAM Address (HEX): 0x%X\n", emuenv_currentHeader.arm9AutoLoadListRamAddress);
    printf("ARM7 Auto Load List RAM Address: %i\n", emuenv_currentHeader.arm7AutoLoadListRamAddress);
    printf("ARM7 Auto Load List RAM Address (HEX): 0x%X\n", emuenv_currentHeader.arm7AutoLoadListRamAddress);
    printf("Secure Area Disable: %i\n", emuenv_currentHeader.secureAreaDisable);
    printf("Secure Area Disable (HEX): 0x%X\n", emuenv_currentHeader.secureAreaDisable);
    printf("ntrRegionRomSize: %i\n", emuenv_currentHeader.ntrRegionRomSize);
    printf("ntrRegionRomSize (HEX); 0x%X\n", emuenv_currentHeader.ntrRegionRomSize);
    printf("ntrRegionRuntimeSize: %i\n", emuenv_currentHeader.ntrRegionRuntimeSize);
    printf("ntrRegionRuntimeSize (HEX): %i\n", emuenv_currentHeader.ntrRegionRuntimeSize);
    printf("totalRomSize: %i\n", emuenv_currentHeader.totalRomSize);
    printf("totalRomSize (HEX): 0x%X\n", emuenv_currentHeader.totalRomSize);
    printf("romHeaderSize: %i\n", emuenv_currentHeader.romHeaderSize);
    printf("romHeaderSize (HEX): 0x%X\n", emuenv_currentHeader.romHeaderSize);
    printf("reserved2: %i\n", emuenv_currentHeader.reserved2);
    printf("reserved2 (HEX): 0x%X\n", emuenv_currentHeader.reserved2);
    printf("logoChecksum: %i\n", emuenv_currentHeader.logoChecksum);
    printf("logoChecksum (HEX): 0x%X\n", emuenv_currentHeader.logoChecksum);
    printf("headerChecksum: %i\n", emuenv_currentHeader.headerChecksum);
    printf("headerChecksum (HEX): 0x%X\n", emuenv_currentHeader.headerChecksum);
    printf("arm9IconOffset: %i\n", emuenv_currentHeader.arm9IconOffset);
    printf("arm9IconOffset (HEX): 0x%X\n", emuenv_currentHeader.arm9IconOffset);
    printf("arm9IconSize: %i\n", emuenv_currentHeader.arm9IconSize);
    printf("arm9IconSize (HEX): 0x%X\n", emuenv_currentHeader.arm9IconSize);
    printf("arm7IconOffset: %i\n", emuenv_currentHeader.arm7IconOffset);
    printf("arm7IconOffset (HEX): 0x%X\n", emuenv_currentHeader.arm7IconOffset);
    printf("arm7IconSize: %i\n", emuenv_currentHeader.arm7IconSize);
    printf("arm7IconSize (HEX): 0x%X\n", emuenv_currentHeader.arm7IconSize);
    printf("titleLogoOffset: %i\n", emuenv_currentHeader.titleLogoOffset);
    printf("titleLogoOffset (HEX): 0x%X\n", emuenv_currentHeader.titleLogoOffset);
    printf("titleLogoSize: %i\n", emuenv_currentHeader.titleLogoSize);
    printf("titleLogoSize (HEX): 0x%X\n", emuenv_currentHeader.titleLogoSize);
    printf("secureAreaCrc: %i\n", emuenv_currentHeader.secureAreaCrc);
    printf("secureAreaCrc (HEX): 0x%X\n", emuenv_currentHeader.secureAreaCrc);
    printf("saveType: %i\n", emuenv_currentHeader.saveType);
    printf("saveType (HEX): 0x%X\n", emuenv_currentHeader.saveType);
    printf("reserved3: revoked\n");
    printf("arm9LoadAddress: %i\n", emuenv_currentHeader.arm9LoadAddress);
    printf("arm9LoadAddress (HEX): 0x%X\n", emuenv_currentHeader.arm9LoadAddress);
    printf("arm7LoadAddress: %i\n", emuenv_currentHeader.arm7LoadAddress);
    printf("arm7LoadAddress (HEX): 0x%X\n", emuenv_currentHeader.arm7LoadAddress);
    printf("reserved4: revoked\n");
    printf("region: %i\n", emuenv_currentHeader.region);
    printf("reserved5: revoked\n");
    printf("arm9OverlayJumpTableOffset: %i\n", emuenv_currentHeader.arm9OverlayJumpTableOffset);
    printf("arm9OverlayJumpTableOffset (HEX): 0x%X\n", emuenv_currentHeader.arm9OverlayJumpTableOffset);
    printf("arm7OverlayJumpTableOffset: %i\n", emuenv_currentHeader.arm7OverlayJumpTableOffset);
    printf("arm7OverlayJumpTableOffset (HEX): 0x%X\n", emuenv_currentHeader.arm7OverlayJumpTableOffset);
    printf("reserved6: revoked\n");
    printf("bannerOffset: %i\n", emuenv_currentHeader.bannerOffset);
    printf("bannerOffset (HEX): 0x%X\n", emuenv_currentHeader.bannerOffset);
    printf("reserved7: revoked\n");
    printf("secureTransferTimeout: %i\n", emuenv_currentHeader.secureTransferTimeout);
    printf("secureTransferTimeout (HEX): 0x%X\n", emuenv_currentHeader.secureTransferTimeout);
    printf("arm9AutoloadListRamAddressEnd: %i\n", emuenv_currentHeader.arm9AutoloadListRamAddressEnd);
    printf("arm9AutoloadListRamAddressEnd: 0x%X\n", emuenv_currentHeader.arm9AutoloadListRamAddressEnd);
    printf("arm7AutoloadListRamAddressEnd: %i\n", emuenv_currentHeader.arm7AutoloadListRamAddressEnd);
    printf("arm7AutoloadListRamAddressEnd: 0x%X\n", emuenv_currentHeader.arm7AutoloadListRamAddressEnd);
    printf("reserved9: revoked\n");
    printf("ntrRegionRomVersion: %c", emuenv_currentHeader.ntrRegionRomVersion);
    printf("reserved9: revoked\n");
    printf("defaultTiming: %i\n", emuenv_currentHeader.defaultTiming);
    printf("defaultTiming (HEX): 0x%X\n", emuenv_currentHeader.defaultTiming);
    printf("arm9AutoloadListRamAddressMain: %i\n", emuenv_currentHeader.arm9AutoloadListRamAddressMain);
    printf("arm9AutoloadListRamAddressMain (HEX): %i\n", emuenv_currentHeader.arm9AutoloadListRamAddressMain);
    printf("arm7AutoloadListRamAddressMain: %i\n", emuenv_currentHeader.arm7AutoloadListRamAddressMain);
    printf("arm7AutoloadListRamAddressMain (HEX): %i\n", emuenv_currentHeader.arm7AutoloadListRamAddressMain);
    printf("reserved10: revoked\n");
    printf("filenameTableOffset: %i\n", emuenv_currentHeader.filenameTableOffset);
    printf("filenameTableOffset (HEX): 0x%X\n", emuenv_currentHeader.filenameTableOffset);
    printf("filenameTableSize: %i\n", emuenv_currentHeader.filenameTableSize);
    printf("filenameTableSize (HEX): 0x%X\n", emuenv_currentHeader.filenameTableSize);
    printf("fileAllocationTableOffset: %i\n", emuenv_currentHeader.fileAllocationTableOffset);
    printf("fileAllocationTableOffset (HEX): 0x%X\n", emuenv_currentHeader.fileAllocationTableOffset);
    printf("fileAllocationTableSize: %i\n", emuenv_currentHeader.fileAllocationTableSize);
    printf("fileAllocationTableSize: 0x%X\n", emuenv_currentHeader.fileAllocationTableSize);
    printf("filenameTable2Offset: %i\n", emuenv_currentHeader.filenameTable2Offset);
    printf("filenameTable2Offset (HEX): 0x%X\n", emuenv_currentHeader.filenameTable2Offset);
    printf("filenameTable2Size: %i\n", emuenv_currentHeader.filenameTable2Size);
    printf("filenameTable2Size (HEX): 0x%X\n", emuenv_currentHeader.filenameTable2Size);
    printf("fileAllocationTable2Offset: %i\n", emuenv_currentHeader.fileAllocationTable2Offset);
    printf("fileAllocationTable2Offset (HEX): 0x%X\n", emuenv_currentHeader.fileAllocationTable2Offset);
    printf("fileAllocationTable2Size: %i\n", emuenv_currentHeader.fileAllocationTable2Size);
    printf("fileAllocationTable2Size (HEX): 0x%X\n", emuenv_currentHeader.fileAllocationTable2Size);
    printf("bannerAnimationOffset: %i\n", emuenv_currentHeader.bannerAnimationOffset);
    printf("bannerAnimationOffset (HEX): 0x%X\n", emuenv_currentHeader.bannerAnimationOffset);
    printf("reserved11: revoked\n");
    printf("ndsRegion: %c\n", emuenv_currentHeader.ndsRegion);
    printf("reserved12: revoked\n");
    printf("=====\n");
    return;
}
