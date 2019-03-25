#include <demangle.h>
#include <stddef.h>
#include <stdlib.h>

char *xmalloc PARAMS((unsigned size)) {
    return malloc(size);
}

char *xrealloc PARAMS((char *mem, unsigned size)) {
    return realloc(mem, size);
}

char * __cxa_demangle(const char *mangled_name, char *output_buffer, size_t *length, int *status) {
    return cplus_demangle(mangled_name, 0);
}
