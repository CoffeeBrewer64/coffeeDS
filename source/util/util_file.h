/*
Name: util_file.h
Description: Header file for file management under the utils.
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#ifndef UTIL_FILE_H_INCLUDED
#define UTIL_FILE_H_INCLUDED

void util_file_writeToFile(const char* fileName, const char* format, ...);
void util_file_makeFile(const char* fileName);

#endif // UTIL_FILE_H_INCLUDED
