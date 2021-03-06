#include "xstring.h"
#include "bm.h"

xstring *xs_alloc(int size)
{
    xstring *tmp = malloc(sizeof(xstring));
    tmp->data = malloc(size );
    tmp->size = size;
    return tmp;
}
int xs_grow(xstring *x, int size)
{
    return xs_realloc(x,x->size+size);
}

int xs_realloc(xstring *x, int size)
{
    x->data = realloc(x->data, size);
    if(x->data == NULL) return 0;
    x->size=size;
    return 1;
}

void xs_free(xstring *x)
{
    free(x->data);
    free(x);
    return;
}
uint8_t *xs_find(xstring *x, xstring *pat)
{
    return boyer_moore(x->data, x->size,pat->data, pat->size);
}
xstring *xs_substr(uint8_t *x, int size)
{
    xstring *t = xs_alloc(size);
    memcpy(t->data, x, size);
    return t;
}

xstring *xs_substr_btwn_char(xstring *x, char a)
{
    uint8_t *t =(uint8_t*)memchr(x->data, a, x->size)+1;

    if(t) {
        int r = t - x->data;
        uint8_t *p =memchr(t, a, x->size-r);
        int sz = p-t;
        return xs_substr(t,sz);
    }
    return NULL;
}
xstring *xs_substr_btwn_chars(xstring *x, char a, char b)
{
    uint8_t *t = (uint8_t*)memchr(x->data, a, x->size)+1;
    uint8_t *p = memchr(x->data, b, x->size);
    if(x!=NULL && t!=NULL) {
        int sz = p-t;
        return xs_substr(t,sz);
    }
    return NULL;
}

int xs_replace(xstring *t, xstring *conan, xstring *leno)
{
    uint8_t *c;
    int delta;
    c = xs_find(t, conan);
    if(!c) return -1;

    delta = conan->size - leno->size;

    if(delta != 0)
        memmove(c+(conan->size-delta),
                c+conan->size,
                t->size + (t->data - (c + conan->size))
               );

    memcpy(c, leno->data, leno->size);
    t->size -=delta;
    xs_realloc(t, t->size);
    t->data[t->size] = '\0';
    return delta;
}

xstring *xs_from_string(char *x)
{
    int sz = strlen(x);
    xstring *t = xs_alloc(sz);
    memcpy(t->data, x, sz);
    return t;
}

int xs_cat(xstring *p, xstring *q)
{
    int t = p->size;
    if(!xs_grow(p, q->size)) return -1;
    memcpy(p->data + t, q->data, q->size);
    return 0;
}


void xs_to_lower(xstring *x)
{
    int i = x->size;
    while(i-->0) x->data[i] = tolower(x->data[i]);
}
void xs_to_upper(xstring *x)
{
    int i = x->size;
    while(i-->0) x->data[i] = toupper(x->data[i]);
}
