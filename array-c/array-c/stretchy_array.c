//
//  stretchy_array.c
//  array-c
//
//  Created by Michael Sanford on 3/16/18.
//  Copyright © 2018 flipside5. All rights reserved.
//

#include "stretchy_array.h"
#include "mem_util.h"
#include "math_util.h"

void *buf__grow(const void *buf, size_t new_len, size_t elem_size) {
    size_t new_cap = MAX(1 + 2*buf_cap(buf), new_len);
    assert(new_len <= new_cap);
    size_t new_size = offsetof(BufHdr, buf) + new_cap*elem_size;
    BufHdr *new_hdr;
    if (buf) {
        new_hdr = xrealloc(buf__hdr(buf), new_size);
    } else {
        new_hdr = xmalloc(new_size);
        new_hdr->len = 0;
    }
    new_hdr->cap = new_cap;
    return new_hdr->buf;
}
