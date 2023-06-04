#include <cpu/common/cpu_read.h>
#include <util/util_log.h>
#include <stdio.h>
#include <types/ndstypes.h>
#include <cart/cart_read.h>

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
    printf("=====\nNDS HEADER DUMP for game with title \"%s\":\n", cartRead_get_gameTitle());
    printf("Game title: %s\n", cartRead_get_gameTitle());
    printf("Game code: %s\n", cartRead_get_gameCode());
    printf("Maker code: %s\n", cartRead_get_makerCode());
    printf("Unit code: %i\n", cartRead_get_unitCode());
    printf("Encryption seed: %s\n", cartRead_get_encryptionSeed());
    printf("Device capacity: %i\n", cartRead_get_deviceCapacity());
    printf("Reserved 1: %s\n", cartRead_get_reserved());
    printf("ROM version: %i\n", cartRead_get_romVersion());
    printf("Internal flags: %i\n", cartRead_get_internalFlags());
    printf("ARM9 ROM Offset: %i\n", cartRead_get_arm9RomOffset());
    printf("ARM9 ROM Offset (HEX): 0x%X\n", cartRead_get_arm9RomOffset());
    printf("ARM9 Entry Address: %i\n", cartRead_get_arm9EntryAddress());
    printf("ARM9 Entry Address (HEX): 0x%X\n", cartRead_get_arm9EntryAddress());
    printf("ARM9 RAM Address: %i\n", cartRead_get_arm9RamAddress());
    printf("ARM9 RAM Address (HEX): 0x%X\n", cartRead_get_arm9RamAddress());
    printf("ARM9 Size: %i\n", cartRead_get_arm9Size());
    printf("ARM9 Size (HEX): 0x%X\n", cartRead_get_arm9Size());
    printf("ARM7 ROM Offset: %i\n", cartRead_get_arm7RomOffset());
    printf("ARM7 ROM Offset (HEX): 0x%X\n", cartRead_get_arm7RomOffset());
    printf("ARM7 Entry Address: %i\n", cartRead_get_arm7EntryAddress());
    printf("ARM7 Entry Address (HEX): 0x%X\n", cartRead_get_arm7EntryAddress());
    printf("ARM7 RAM Address: %i\n", cartRead_get_arm7RamAddress());
    printf("ARM7 RAM Address (HEX): 0x%X\n", cartRead_get_arm7RamAddress());
    printf("ARM7 Size: %i\n", cartRead_get_arm7Size());
    printf("ARM7 Size (HEX): 0x%X\n", cartRead_get_arm7Size());
    printf("fnt offset: %i\n", cartRead_get_fntOffset());
    printf("fnt offset (HEX): 0x%X\n", cartRead_get_fntSize());
    printf("fat offset: %i\n", cartRead_get_fatOffset());
    printf("fat offset (HEX): 0x%X\n", cartRead_get_fatOffset());
    printf("fat size: %i\n", cartRead_get_fatSize());
    printf("fat size (HEX): 0x%X\n", cartRead_get_fatSize());
    printf("ARM9 Overlay Offset: %i\n", cartRead_get_arm9OverlayOffset());
    printf("ARM9 Overlay Offset (HEX): 0x%X\n", cartRead_get_arm9OverlayOffset());
    printf("ARM9 Overlay Size: %i\n", cartRead_get_arm9OverlaySize());
    printf("ARM9 Overlay Size (HEX): 0x%X\n", cartRead_get_arm9OverlaySize());
    printf("ARM7 Overlay Size: %i\n", cartRead_get_arm7OverlaySize());
    printf("ARM7 Overlay Size (HEX): 0x%X\n", cartRead_get_arm7OverlaySize());
    printf("Normal Card Control Reg(ister?) Settings: %i\n", cartRead_get_normalCardControlRegSettings());
    printf("Normal Card Control Reg(ister?) Settings (HEX): 0x%X\n", cartRead_get_normalCardControlRegSettings());
    printf("Secure Card Control Reg(ister?) Settings: %i\n", cartRead_get_secureCardControlRegSettings());
    printf("Secure Card Control Reg(ister?) Settings (HEX): 0x%X\n", cartRead_get_secureCardControlRegSettings());
    printf("Icon Title Offset: %i\n", cartRead_get_iconTitleOffset());
    printf("Icon Title Offset (HEX): 0x%X\n", cartRead_get_iconTitleOffset());
    printf("Secure Area Checksum: %i\n", cartRead_get_secureAreaChecksum());
    printf("Secure Area Checksum (HEX): 0x%X\n", cartRead_get_secureAreaChecksum());
    printf("Secure Area Delay: %i\n", cartRead_get_secureAreaDelay());
    printf("Secure Area Delay (HEX): 0x%X\n", cartRead_get_secureAreaDelay());
    printf("ARM9 Auto Load List RAM Address: %i\n", cartRead_get_arm9AutoLoadListRamAddress());
    printf("ARM9 Auto Load List RAM Address (HEX): 0x%X\n", cartRead_get_arm9AutoLoadListRamAddress());
    printf("ARM7 Auto Load List RAM Address: %i\n", cartRead_get_arm7AutoLoadListRamAddress());
    printf("ARM7 Auto Load List RAM Address (HEX): 0x%X\n", cartRead_get_arm7AutoLoadListRamAddress());
    printf("Secure Area Disable: %i\n", cartRead_get_secureAreaDisable());
    printf("Secure Area Disable (HEX): 0x%X\n", cartRead_get_secureAreaDisable());
    printf("ntrRegionRomSize: %i\n", cartRead_get_ntrRegionRomSize());
    printf("ntrRegionRomSize (HEX); 0x%X\n", cartRead_get_ntrRegionRomSize());
    printf("ntrRegionRuntimeSize: %i\n", cartRead_get_ntrRegionRuntimeSize());
    printf("ntrRegionRuntimeSize (HEX): %i\n", cartRead_get_ntrRegionRuntimeSize());
    printf("totalRomSize: %i\n", cartRead_get_totalRomSize());
    printf("totalRomSize (HEX): 0x%X\n", cartRead_get_totalRomSize());
    printf("romHeaderSize: %i\n", cartRead_get_romHeaderSize());
    printf("romHeaderSize (HEX): 0x%X\n", cartRead_get_romHeaderSize());
    printf("reserved2: %i\n", cartRead_get_reserved2());
    printf("reserved2 (HEX): 0x%X\n", cartRead_get_reserved2());
    printf("logoChecksum: %i\n", cartRead_get_logoChecksum());
    printf("logoChecksum (HEX): 0x%X\n", cartRead_get_logoChecksum());
    printf("headerChecksum: %i\n", cartRead_get_headerChecksum());
    printf("headerChecksum (HEX): 0x%X\n", cartRead_get_headerChecksum());
    printf("arm9IconOffset: %i\n", cartRead_get_arm9IconOffset());
    printf("arm9IconOffset (HEX): 0x%X\n", cartRead_get_arm9IconOffset());
    printf("arm9IconSize: %i\n", cartRead_get_arm9IconSize());
    printf("arm9IconSize (HEX): 0x%X\n", cartRead_get_arm9IconSize());
    printf("arm7IconOffset: %i\n", cartRead_get_arm7IconOffset());
    printf("arm7IconOffset (HEX): 0x%X\n", cartRead_get_arm7IconOffset());
    printf("arm7IconSize: %i\n", cartRead_get_arm7IconSize());
    printf("arm7IconSize (HEX): 0x%X\n", cartRead_get_arm7IconSize());
    printf("titleLogoOffset: %i\n", cartRead_get_titleLogoOffset());
    printf("titleLogoOffset (HEX): 0x%X\n", cartRead_get_titleLogoOffset());
    printf("titleLogoSize: %i\n", cartRead_get_titleLogoSize());
    printf("titleLogoSize (HEX): 0x%X\n", cartRead_get_titleLogoSize());
    printf("secureAreaCrc: %i\n", cartRead_get_secureAreaCrc());
    printf("secureAreaCrc (HEX): 0x%X\n", cartRead_get_secureAreaCrc());
    printf("saveType: %i\n", cartRead_get_saveType());
    printf("saveType (HEX): 0x%X\n", cartRead_get_saveType());
    printf("reserved3: revoked\n");
    printf("arm9LoadAddress: %i\n", cartRead_get_arm9LoadAddress());
    printf("arm9LoadAddress (HEX): 0x%X\n", cartRead_get_arm9LoadAddress());
    printf("arm7LoadAddress: %i\n", cartRead_get_arm7LoadAddress());
    printf("arm7LoadAddress (HEX): 0x%X\n", cartRead_get_arm7LoadAddress());
    printf("reserved4: revoked\n");
    printf("region: %i\n", cartRead_get_region());
    printf("reserved5: revoked\n");
    printf("arm9OverlayJumpTableOffset: %i\n", cartRead_get_arm9OverlayJumpTableOffset());
    printf("arm9OverlayJumpTableOffset (HEX): 0x%X\n", cartRead_get_arm9OverlayJumpTableOffset());
    printf("arm7OverlayJumpTableOffset: %i\n", cartRead_get_arm7OverlayJumpTableOffset());
    printf("arm7OverlayJumpTableOffset (HEX): 0x%X\n", cartRead_get_arm7OverlayJumpTableOffset());
    printf("reserved6: revoked\n");
    printf("bannerOffset: %i\n", cartRead_get_bannerOffset());
    printf("bannerOffset (HEX): 0x%X\n", cartRead_get_bannerOffset());
    printf("reserved7: revoked\n");
    printf("secureTransferTimeout: %i\n", cartRead_get_secureTransferTimeout());
    printf("secureTransferTimeout (HEX): 0x%X\n", cartRead_get_secureTransferTimeout());
    printf("arm9AutoloadListRamAddressEnd: %i\n", cartRead_get_arm9AutoloadListRamAddressEnd());
    printf("arm9AutoloadListRamAddressEnd: 0x%X\n", cartRead_get_arm9AutoloadListRamAddressEnd());
    printf("arm7AutoloadListRamAddressEnd: %i\n", cartRead_get_arm7AutoloadListRamAddressEnd());
    printf("arm7AutoloadListRamAddressEnd: 0x%X\n", cartRead_get_arm7AutoloadListRamAddressEnd());
    printf("reserved9: revoked\n");
    printf("ntrRegionRomVersion: %c", cartRead_get_ntrRegionRomVersion());
    printf("reserved9: revoked\n");
    printf("defaultTiming: %i\n", cartRead_get_defaultTiming());
    printf("defaultTiming (HEX): 0x%X\n", cartRead_get_defaultTiming());
    printf("arm9AutoloadListRamAddressMain: %i\n", cartRead_get_arm9AutoloadListRamAddressMain());
    printf("arm9AutoloadListRamAddressMain (HEX): %i\n", cartRead_get_arm9AutoloadListRamAddressMain());
    printf("arm7AutoloadListRamAddressMain: %i\n", cartRead_get_arm7AutoloadListRamAddressMain());
    printf("arm7AutoloadListRamAddressMain (HEX): %i\n", cartRead_get_arm7AutoloadListRamAddressMain());
    printf("reserved10: revoked\n");
    printf("filenameTableOffset: %i\n", cartRead_get_filenameTableOffset());
    printf("filenameTableOffset (HEX): 0x%X\n", cartRead_get_filenameTableOffset());
    printf("filenameTableSize: %i\n", cartRead_get_filenameTableSize());
    printf("filenameTableSize (HEX): 0x%X\n", cartRead_get_filenameTableSize());
    printf("fileAllocationTableOffset: %i\n", cartRead_get_fileAllocationTableOffset());
    printf("fileAllocationTableOffset (HEX): 0x%X\n", cartRead_get_fileAllocationTableOffset());
    printf("fileAllocationTableSize: %i\n", cartRead_get_fileAllocationTableSize());
    printf("fileAllocationTableSize: 0x%X\n", cartRead_get_fileAllocationTableSize());
    printf("filenameTable2Offset: %i\n", cartRead_get_filenameTable2Offset());
    printf("filenameTable2Offset (HEX): 0x%X\n", cartRead_get_filenameTable2Offset());
    printf("filenameTable2Size: %i\n", cartRead_get_filenameTable2Size());
    printf("filenameTable2Size (HEX): 0x%X\n", cartRead_get_filenameTable2Size());
    printf("fileAllocationTable2Offset: %i\n", cartRead_get_fileAllocationTable2Offset());
    printf("fileAllocationTable2Offset (HEX): 0x%X\n", cartRead_get_fileAllocationTable2Offset());
    printf("fileAllocationTable2Size: %i\n", cartRead_get_fileAllocationTable2Size());
    printf("fileAllocationTable2Size (HEX): 0x%X\n", cartRead_get_fileAllocationTable2Size());
    printf("bannerAnimationOffset: %i\n", cartRead_get_bannerAnimationOffset());
    printf("bannerAnimationOffset (HEX): 0x%X\n", cartRead_get_bannerAnimationOffset());
    printf("reserved11: revoked\n");
    printf("ndsRegion: %c\n", cartRead_get_ndsRegion());
    printf("reserved12: revoked\n");
    printf("=====\n");
    return;
}
