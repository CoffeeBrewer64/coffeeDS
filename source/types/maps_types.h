/*
Name: maps_types.h
Description: Header file for the maps typedefs
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#ifndef MAPS_TYPES_H_INCLUDED
#define MAPS_TYPES_H_INCLUDED

#include <types/ndstypes.h>

typedef struct
{
    const char* map_id;
    uint32 map_value;
    int argument_count;
    const char* description; // Pull from https://problemkaputt.de/gbatek.htm#dsiomaps
    int permissions; // 0 = read, 1 = write, 2 = read and write
} nds_io_map;

typedef struct
{
    const char* map_id;
    uint32 map_value;
    int argument_count;
    const char* description; // Pull from https://problemkaputt.de/gbatek.htm#dsiiomap
    int permissions; // 0 = read, 1 = write, 2 = read and write
} ndsi_io_map;

typedef struct
{
    const char* map_id;
    uint32 map_value;
    int argument_count;
    int permissions; // 0 = read, 1 = write, 2 = read and write
    const char* name;
    const char* description;
} gba_io_map;

// TODO: DS 3D map type
// TODO: DS RAM map type
// TODO: DSi IO map type

#endif // MAPS_TYPES_H_INCLUDED
