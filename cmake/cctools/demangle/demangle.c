#include <stddef.h>
#include <demangle.h>

char * __cxa_demangle(const char *mangled_name, char *output_buffer, size_t *length, int *status) {
    return cplus_demangle(mangled_name, 0);
}
