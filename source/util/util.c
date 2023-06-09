/*
Name: util.c
Description: Source file for all utils
License: MIT License Copyright (c) CoffeeBrewer64 2023
Last author: CoffeeBrewer64
Original author: CoffeeBrewer64
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#include <util/util_strings.h>
#include <util/util_log.h>
#include <util/util_file.h>

bool _isFirstLogFile = true;

char* util_strings_intToChar(int number)
{
    static char str[12];
    snprintf(str, sizeof(str), "%d", number);
    return str;
}

void LOG(const char* format, ...)
{
    if (_isFirstLogFile == true)
    {
        remove("LOG.txt");
    }
    else
    {
        _isFirstLogFile = false;
    }

    FILE* file = fopen("LOG.txt", "a");
    if (file == NULL)
    {
        printf("Error opening log file.\n");
        return;
    }

    va_list args;
    va_start(args, format);

    // Check if format ends with a newline character
    size_t format_len = strlen(format);
    if (format_len > 0 && format[format_len - 1] != '\n')
    {
        // Format does not end with newline, so add it
        vfprintf(stdout, format, args);
        vfprintf(file, format, args);
        printf("\n");
        fprintf(file, "\n");
    }
    else
    {
        // Format already ends with newline
        vprintf(format, args);
        vfprintf(file, format, args);
    }

    va_end(args);

    fclose(file);
    _isFirstLogFile = false;
    return;
}

void util_file_writeToFile(const char* fileName, const char* format, ...)
{
    FILE* file = fopen(fileName, "a");
    if (file == NULL)
    {
        printf("Error opening log file.\n");
        return;
    }

    va_list args;
    va_start(args, format);

    // Check if format ends with a newline character
    size_t format_len = strlen(format);
    if (format_len > 0 && format[format_len - 1] != '\n')
    {
        // Format does not end with newline, so add it
        vfprintf(stdout, format, args);
        vfprintf(file, format, args);
        printf("\n");
        fprintf(file, "\n");
    }
    else
    {
        // Format already ends with newline
        vprintf(format, args);
        vfprintf(file, format, args);
    }

    va_end(args);

    fclose(file);
    return;
}

void util_file_makeFile(const char* fileName)
{
    FILE* file = fopen(fileName, "w");
    if (file == NULL)
    {
        LOG("Could not create file with name \"%s\"", fileName);
    }
    fclose(file);
    return;
}
