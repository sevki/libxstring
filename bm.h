#ifndef _XSTRING_BM_H

#include <stdint.h>
#include <stdlib.h>

#define _XSTRING_BM_H

uint8_t* boyer_moore (uint8_t *string, uint32_t stringlen, uint8_t *pat, uint32_t patlen);

#endif
