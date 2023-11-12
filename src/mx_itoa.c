#include "libmx.h"

char *mx_itoa(int number) {
    if (number == 0) return mx_strdup("0");

    int buffer_size = mx_int_length(number) + (number < 0 ? 1 : 0) + 1;

    char *number_string = mx_strnew(buffer_size);

    if (number_string == NULL) return NULL;

    int chars_written = mx_snprintf(number_string, buffer_size, "%d", number);

    if (chars_written < 0 || chars_written >= buffer_size) {
        free(number_string);
        return NULL;
    }

    return number_string;
}
