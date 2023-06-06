#ifndef MAPS_NDS_IO_H_INCLUDED
#define MAPS_NDS_IO_H_INCLUDED

#include <types/maps_types.h>
#include <types/ndstypes.h>

/// ARM9 Display Engine A ///
nds_io_map NDS_IO_MAP_4000000h = { "4000000h", 4, "2D Engine A - DISPCNT - LCD Control", 2};
nds_io_map NDS_IO_MAP_4000004h = { "4000004h", 2, "2D Engine A+B - DISPSTAT - General LCD Status", 2};
nds_io_map NDS_IO_MAP_4000006h = { "4000006h", 2, "2D Engine A+B - VCOUNT - Vertical Counter", 0};
nds_io_map NDS_IO_MAP_4000008h = { "4000008h", 50, "2D Engine A (same registers as GBA, some changed bits)", 2};
nds_io_map NDS_IO_MAP_4000060h = { "4000060h", 2, "DISP3DCNT - 3D Display Control Register", 2};
nds_io_map NDS_IO_MAP_4000064h = { "4000064h", 4, "DISPCAPCNT - Display Capture Control Register", 2};
nds_io_map NDS_IO_MAP_4000068h = { "4000068h", 4, "DISP_MMEM_FIFO - Main Memory Display FIFO", 2}; // Assuming can read
nds_io_map NDS_IO_MAP_400006Ch = { "400006Ch", 2, "2D Engine A - MASTER_BRIGHT - Master Brightness Up/Down", 2}; // Assuming can read and/or write

/// ARM9 DMA, Timers, and Keypad ///
nds_io_map NDS_IO_MAP_40000B0h = { "40000B0h", 30, "DMA Channel 0..3", 2}; // Assuming read and write
nds_io_map NDS_IO_MAP_40000E0h = { "40000E0h", 10, "DMA FILL Registers for Channel 0..3", 2}; // Assuming read and write
nds_io_map NDS_IO_MAP_4000100h = { "4000100h", 10, "Timers 0..3", 2}; //Assuming read and write
nds_io_map NDS_IO_MAP_4000130h = { "4000130h", 2, "KEYINPUT", 2}; // Assuming read and write
nds_io_map NDS_IO_MAP_4000132h = { "4000132h", 2, "KEYCNT", 2}; // Assuming read and write

#endif // MAPS_NDS_IO_H_INCLUDED