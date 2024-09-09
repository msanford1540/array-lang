//
//  mem_util.h
//  array-c
//
//  Created by Michael Sanford on 3/16/18.
//  Copyright © 2018 flipside5. All rights reserved.
//

#ifndef mem_util_h
#define mem_util_h

#include <stdio.h>

#define xassert(cond) ( (cond) ? 0 : (perror("assert failure"), exit(1), -1) )

void *xrealloc(void *ptr, size_t num_bytes);
void *xmalloc(size_t num_bytes);

#endif /* mem_util_h */
