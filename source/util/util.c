#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#include <util/util_strings.h>
#include <util/util_log.h>

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
