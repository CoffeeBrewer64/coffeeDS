/*
Name: cart_read.c
Description: File for reading data from the "cart" (cartridge, the .nds file)
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#include <stdio.h>

#include <types/ndstypes.h>
#include <util/util_log.h>
#include <emuenv/emuenv.h>

#include <cart/cart_read.h>

int cartRead_init()
{
    LOG("Starting cartRead...");
    FILE* file = fopen("game.nds", "rb");
    if (file == NULL)
    {
        LOG("Could not init cart reading: game.nds does not exist/could not be found");
        return -1;
    }

    if (fread(&emuenv_currentHeader, sizeof(ndsrom_header), 1, file) != 1)
    {
        LOG("Failed to read the NDS ROM header.");
        fclose(file);
        return -1;
    }
    LOG("Started cartRead!");
    return 0;
}
