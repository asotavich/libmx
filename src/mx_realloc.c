#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    }
    
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(size);
    
    if (new_ptr) {
        size_t old_size = malloc_usable_size(ptr);
        mx_memcpy(new_ptr, ptr, old_size < size ? old_size : size);
        free(ptr);
    }

    return new_ptr;
}
