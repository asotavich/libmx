#include "libmx.h"

int mx_snprintf(char *str, size_t size, const char *format, ...) {
    va_list args;
    va_start(args, format);

    int chars_written = vsnprintf(str, size, format, args);

    va_end(args);

    return chars_written;
}
