/*
  libxstring. Extended String Library.
  http://github.com/Sevki/libxstring

  Boyer Moore Implementation from Wikipedia under Creative Commons 3
  http://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_string_search_algorithm

  Copyright (c) 2013, Sevki Hasirci <s@sevki.org>
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
  * Neither the name of  nor the names of its contributors may be used
  to endorse or promote products derived from this software without
  specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _XSTRING_H
#define _XSTRING_H


#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
typedef struct
{
    uint8_t *data;
    int size;
} xstring;

 /* Memory operations */
xstring *xs_alloc(int size);
int xs_realloc(xstring *x, int size);
int xs_grow(xstring *x, int size);
void xs_free();

 /* String utils */
xstring *xs_from_string(char *x);
int xs_cat(xstring *p, xstring *q);
void xs_to_lower(xstring *x);
void xs_to_upper(xstring *x);

 /* String Search */
uint8_t *xs_find(xstring *x, xstring *pat);
xstring *xs_substr_btwn_char(xstring *x, char a);
xstring *xs_substr_btwn_chars(xstring *x, char a, char b);

 /* String Replace  */
int xs_replace(xstring *t, xstring *conan, xstring *leno);

#endif
