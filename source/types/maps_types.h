#ifndef MAPS_TYPES_H_INCLUDED
#define MAPS_TYPES_H_INCLUDED

#include <stdbool.h>

typedef struct
{
    const char* map_id;
    int argument_count;
    const char* description; // Pull from https://problemkaputt.de/gbatek.htm#dsiomaps
} nds_io_map;

typedef struct
{
    const char* map_id;
    int argument_count;
    const char* description; // Pull from https://problemkaputt.de/gbatek.htm#dsiiomap
} ndsi_io_map;

// TODO: DS 3D map type
// TODO: DS RAM map type
// TODO: GBA IO map type

#endif // MAPS_TYPES_H_INCLUDED
