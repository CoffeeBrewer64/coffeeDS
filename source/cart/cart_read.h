#ifndef CART_READ_H_INCLUDED
#define CART_READ_H_INCLUDED

#include <types/ndstypes.h>

ndsrom_header current_header;

int cartRead_init();
unsigned char* cartRead_get_gameTitle();
unsigned char* cartRead_get_gameCode();
unsigned char* cartRead_get_makerCode();
unsigned char cartRead_get_unitCode();
unsigned char* cartRead_get_encryptionSeed();
unsigned char cartRead_get_deviceCapacity();
unsigned char* cartRead_get_reserved();
unsigned char cartRead_get_romVersion();
unsigned char cartRead_get_internalFlags();
unsigned int cartRead_get_arm9RomOffset();
unsigned int cartRead_get_arm9EntryAddress();
unsigned int cartRead_get_arm9RamAddress();
unsigned int cartRead_get_arm9Size();
unsigned int cartRead_get_arm7RomOffset();
unsigned int cartRead_get_arm7EntryAddress();
unsigned int cartRead_get_arm7RamAddress();
unsigned int cartRead_get_arm7Size();
unsigned int cartRead_get_fntOffset();
unsigned int cartRead_get_fntSize();
unsigned int cartRead_get_fatOffset();
unsigned int cartRead_get_fatSize();
unsigned int cartRead_get_arm9OverlayOffset();
unsigned int cartRead_get_arm9OverlaySize();
unsigned int cartRead_get_arm7OverlayOffset();
unsigned int cartRead_get_arm7OverlaySize();
unsigned short cartRead_get_normalCardControlRegSettings();
unsigned short cartRead_get_secureCardControlRegSettings();
unsigned int cartRead_get_iconTitleOffset();
unsigned short cartRead_get_secureAreaChecksum();
unsigned short cartRead_get_secureAreaDelay();
unsigned int cartRead_get_arm9AutoLoadListRamAddress();
unsigned int cartRead_get_arm7AutoLoadListRamAddress();
unsigned short cartRead_get_secureAreaDisable();
unsigned short cartRead_get_ntrRegionRomSize();
unsigned short cartRead_get_ntrRegionRuntimeSize();
unsigned int cartRead_get_totalRomSize();
unsigned short cartRead_get_romHeaderSize();
unsigned short cartRead_get_reserved2();
unsigned short cartRead_get_logoChecksum();
unsigned short cartRead_get_headerChecksum();

#endif // CART_READ_H_INCLUDED
