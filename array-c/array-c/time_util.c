//
//  time_util.c
//  array-c
//
//  Created by Michael Sanford on 3/16/18.
//  Copyright © 2018 flipside5. All rights reserved.
//

#include "time_util.h"
#include <math.h>

long clock_gettime_ms(clockid_t __clock_id) {
    long ms;
    time_t secs;
    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);
    secs  = spec.tv_sec;
    ms = round(spec.tv_nsec / 1.0e6);
    while (ms > 999) {
        secs++;
        ms -= 1000;
    }
    return secs*1000 + ms;
}

long clock_gettime_microseconds(clockid_t __clock_id) {
    long microseconds;
    time_t secs;
    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);
    secs  = spec.tv_sec;
    microseconds = round(spec.tv_nsec / 1.0e3);
    while (microseconds > 999999) {
        secs++;
        microseconds -= 1000000;
    }
    return secs*1000000 + microseconds;
}
