/*
Name: maps_nds_io.h
Description: Header file for the NDS IO port maps
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#ifndef MAPS_NDS_IO_H_INCLUDED
#define MAPS_NDS_IO_H_INCLUDED

#include <types/maps_types.h>
#include <types/ndstypes.h>

/// ARM9 Display Engine A ///
nds_io_map NDS_IO_MAP_4000000h = { "4000000h", 0x4000000, 4, "2D Engine A - DISPCNT - LCD Control", 2};
nds_io_map NDS_IO_MAP_4000004h = { "4000004h", 0x4000004, 2, "2D Engine A+B - DISPSTAT - General LCD Status", 2};
nds_io_map NDS_IO_MAP_4000006h = { "4000006h", 0x4000006, 2, "2D Engine A+B - VCOUNT - Vertical Counter", 0};
nds_io_map NDS_IO_MAP_4000008h = { "4000008h", 0x4000008, 50, "2D Engine A (same registers as GBA, some changed bits)", 2};
nds_io_map NDS_IO_MAP_4000060h = { "4000060h", 0x4000060, 2, "DISP3DCNT - 3D Display Control Register", 2};
nds_io_map NDS_IO_MAP_4000064h = { "4000064h", 0x4000064, 4, "DISPCAPCNT - Display Capture Control Register", 2};
nds_io_map NDS_IO_MAP_4000068h = { "4000068h", 0x4000068, 4, "DISP_MMEM_FIFO - Main Memory Display FIFO", 2};
nds_io_map NDS_IO_MAP_400006Ch = { "400006Ch", 0x400006C, 2, "2D Engine A - MASTER_BRIGHT - Master Brightness Up/Down", 2};

/// ARM9 DMA, Timers, and Keypad ///
nds_io_map NDS_IO_MAP_40000B0h = { "40000B0h", 0x40000B0, 30, "DMA Channel 0..3", 2};
nds_io_map NDS_IO_MAP_40000E0h = { "40000E0h", 0x40000E0, 10, "DMA FILL Registers for Channel 0..3", 2};
nds_io_map NDS_IO_MAP_4000100h = { "4000100h", 0x4000100, 10, "Timers 0..3", 2};
nds_io_map NDS_IO_MAP_4000130h = { "4000130h", 0x4000130, 2, "KEYINPUT", 2};
nds_io_map NDS_IO_MAP_4000132h = { "4000132h", 0x4000132, 2, "KEYCNT", 2};

/// ARM9 IPC/ROM
nds_io_map NDS_IO_MAP_4000180h = { "4000180h", 0x4000180, 2, "IPCSYNC - IPC Synchronize Register", 2};
nds_io_map NDS_IO_MAP_4000184h = { "4000184h", 0x4000184, 2, "IPCFIFOCNT - IPC Fifo Control Register", 2};
nds_io_map NDS_IO_MAP_4000188h = { "4000188h", 0x4000188, 4, "IPCFIFOSEND - IPC Send Fifo", 2};
nds_io_map NDS_IO_MAP_40001A0h = { "40001A0h", 0x40001A0, 2, "AUXSPICNT - Gamecard ROM and SPI Control", 2};
nds_io_map NDS_IO_MAP_40001A2h = { "40001A2h", 0x40001A2, 2, "AUXSPIDATA - Gamecard SPI Bus Data/Strobe", 2};
nds_io_map NDS_IO_MAP_40001A4h = { "40001A4h", 0x40001A4, 4, "Gamecard bus timing/control", 2};
nds_io_map NDS_IO_MAP_40001A8h = { "40001A8h", 0x40001A8, 8, "Gamecard bus 8-byte command out", 2};
nds_io_map NDS_IO_MAP_40001B0h = { "40001B0h", 0x40001B0, 4, "Gamecard Encryption Seed 0 Lower 32bit", 2};
nds_io_map NDS_IO_MAP_40001B4h = { "40001B4h", 0x40001B4, 4, "Gamecard Encryption Seed 1 Lower 32bit", 2};
nds_io_map NDS_IO_MAP_40001B8h = { "40001B8h", 0x40001B8, 2, "Gamecard Encryption Seed 0 Upper 7bit", 2};
nds_io_map NDS_IO_MAP_40001BAh = { "40001BAh", 0x40001BA, 2, "Gamecard Encryption Seed 1 Upper 7bit", 2};

#endif // MAPS_NDS_IO_H_INCLUDED
