/**************************************************************************
 *
 * Copyright (C) 2019 Chromium.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
    **************************************************************************/

#ifndef VIRGL_UTIL_H
#define VIRGL_UTIL_H

#include <stdint.h>
#include <stdbool.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define TRACE_WITH_PERFETTO 1
#define TRACE_WITH_STDERR 2

#define BIT(n)                   (UINT32_C(1) << (n))

static inline bool has_bit(uint32_t mask, uint32_t bit)
{
    return !!(mask & bit);
}

static inline bool has_bits(uint32_t mask, uint32_t bits)
{
    return !!((mask & bits) == bits);
}

static inline bool is_only_bit(uint32_t mask, uint32_t bit)
{
    return (mask == bit);
}

unsigned hash_func_u32(void *key);

int compare_func(void *key1, void *key2);

bool has_eventfd(void);
int create_eventfd(unsigned int initval);
int write_eventfd(int fd, uint64_t val);
void flush_eventfd(int fd);

#ifdef ENABLE_TRACING
void trace_init(void);
const char *trace_begin(const char *scope);
void trace_end(const char **dummy);

#define TRACE_INIT() trace_init()
#define TRACE_FUNC() TRACE_SCOPE(__func__)

#define TRACE_SCOPE(SCOPE) \
   const char *trace_dummy __attribute__((cleanup (trace_end), unused)) = \
   trace_begin(SCOPE)

#else
#define TRACE_INIT()
#define TRACE_FUNC()
#define TRACE_SCOPE(SCOPE)
#endif

#endif /* VIRGL_UTIL_H */
