/*
Name: cart_read.h
Description: Header for cart_read.c
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#ifndef CART_READ_H_INCLUDED
#define CART_READ_H_INCLUDED

#include <types/ndstypes.h>

int cartRead_init();
unsigned char* cart_read_gameTitle();
unsigned char* cart_read_gameCode();
unsigned char* cart_read_makerCode();
unsigned char cart_read_unitCode();
unsigned char* cart_read_encryptionSeed();
unsigned char cart_read_deviceCapacity();
unsigned char* cart_read_reserved();
unsigned char cart_read_romVersion();
unsigned char cart_read_internalFlags();
unsigned int cart_read_arm9RomOffset();
unsigned int cart_read_arm9EntryAddress();
unsigned int cart_read_arm9RamAddress();
unsigned int cart_read_arm9Size();
unsigned int cart_read_arm7RomOffset();
unsigned int cart_read_arm7EntryAddress();
unsigned int cart_read_arm7RamAddress();
unsigned int cart_read_arm7Size();
unsigned int cart_read_fntOffset();
unsigned int cart_read_fntSize();
unsigned int cart_read_fatOffset();
unsigned int cart_read_fatSize();
unsigned int cart_read_arm9OverlayOffset();
unsigned int cart_read_arm9OverlaySize();
unsigned int cart_read_arm7OverlayOffset();
unsigned int cart_read_arm7OverlaySize();
unsigned short cart_read_normalCardControlRegSettings();
unsigned short cart_read_secureCardControlRegSettings();
unsigned int cart_read_iconTitleOffset();
unsigned short cart_read_secureAreaChecksum();
unsigned short cart_read_secureAreaDelay();
unsigned int cart_read_arm9AutoLoadListRamAddress();
unsigned int cart_read_arm7AutoLoadListRamAddress();
unsigned short cart_read_secureAreaDisable();
unsigned short cart_read_ntrRegionRomSize();
unsigned short cart_read_ntrRegionRuntimeSize();
unsigned int cart_read_totalRomSize();
unsigned short cart_read_romHeaderSize();
unsigned short cart_read_reserved2();
unsigned short cart_read_logoChecksum();
unsigned short cart_read_headerChecksum();
unsigned int cart_read_arm9IconOffset();
unsigned int cart_read_arm9IconSize();
unsigned int cart_read_arm7IconOffset();
unsigned int cart_read_arm7IconSize();
unsigned int cart_read_titleLogoOffset();
unsigned int cart_read_titleLogoSize();
unsigned int cart_read_secureAreaCrc();
unsigned int cart_read_romSize();
unsigned int cart_read_saveType();
unsigned int* cart_read_reserved3();
unsigned int cart_read_arm9LoadAddress();
unsigned int cart_read_arm7LoadAddress();
unsigned char* cart_read_reserved4();
unsigned short cart_read_region();
unsigned char* cart_read_reserved5();
unsigned int cart_read_arm9OverlayJumpTableOffset();
unsigned int cart_read_arm7OverlayJumpTableOffset();
unsigned int* cart_read_reserved6();
unsigned int cart_read_bannerOffset();
unsigned char* cart_read_reserved7();
unsigned int cart_read_secureTransferTimeout();
unsigned int cart_read_arm9AutoloadListRamAddressEnd();
unsigned int cart_read_arm7AutoloadListRamAddressEnd();
unsigned char* cart_read_reserved8();
unsigned char cart_read_ntrRegionRomVersion();
unsigned char* cart_read_reserved9();
unsigned int cart_read_defaultTiming();
unsigned int cart_read_arm9AutoloadListRamAddressMain();
unsigned int cart_read_arm7AutoloadListRamAddressMain();
unsigned int* cart_read_reserved10();
unsigned int cart_read_filenameTableOffset();
unsigned int cart_read_filenameTableSize();
unsigned int cart_read_fileAllocationTableOffset();
unsigned int cart_read_fileAllocationTableSize();
unsigned int cart_read_filenameTable2Offset();
unsigned int cart_read_filenameTable2Size();
unsigned int cart_read_fileAllocationTable2Offset();
unsigned int cart_read_fileAllocationTable2Size();
unsigned int cart_read_bannerAnimationOffset();
unsigned int* cart_read_reserved11();
unsigned char cart_read_ndsRegion();
unsigned char* cart_read_reserved12();

#endif // CART_READ_H_INCLUDED
