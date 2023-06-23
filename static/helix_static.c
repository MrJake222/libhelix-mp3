#include "helix_static.h"

void clear_buf(void *buf, int nBytes) {
    int i;
    unsigned char *cbuf = (unsigned char *)buf;

    for (i = 0; i < nBytes; i++)
        cbuf[i] = 0;
}