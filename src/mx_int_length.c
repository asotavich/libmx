#include "libmx.h"

int mx_int_length(int number) {
    if (number == 0) {
        return 1;
    }

    int length = 0;

    if (number < 0) {
        length++;
        number = -number;
    }

    while (number != 0) {
        number /= 10;
        length++;
    }

    return length;
}
