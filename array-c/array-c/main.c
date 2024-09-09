//
//  main.c
//  array-c
//
//  Created by Michael Sanford on 3/16/18.
//  Copyright © 2018 flipside5. All rights reserved.
//

#include "stretchy_array.h"
#include "mem_util.h"
#include "time_util.h"

void array_test(int count) {
    int *buf = NULL;
    xassert(buf_len(buf) == 0);
    for (int i = 0; i < count; i++) {
        buf_push(buf, i);
    }
    xassert(buf_len(buf) == count);
    for (int i = 0; i < buf_len(buf); i++) {
        xassert(buf[i] == i);
    }
    buf_free(buf);
    xassert(buf == NULL);
    xassert(buf_len(buf) == 0);
}

void show_test(int pass, int count) {
    printf("%d: [starting] steps=%d\n", pass, count);
    long startMicroseconds = gettime_microseconds();
    array_test(count);
  long endMicroseconds = gettime_microseconds();
    long durationInMicroseconds = endMicroseconds - startMicroseconds;
    float duratinInMilliseconds = (float)durationInMicroseconds / 1000.0;
    printf("%d: [done] time=%.3f ms\n\n", pass, duratinInMilliseconds);
}

int main(int argc, const char * argv[]) {
    int steps = 1000000;
    int passes = 2;
    
    printf("C\n");
    for (int i = 0; i < passes; i++) {
        show_test(i, steps);
    }
    
    return 0;
}
