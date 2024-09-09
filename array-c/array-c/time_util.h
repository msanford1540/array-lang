//
//  time_util.h
//  array-c
//
//  Created by Michael Sanford on 3/16/18.
//  Copyright © 2018 flipside5. All rights reserved.
//

#ifndef time_util_h
#define time_util_h

#include <time.h>

#define gettime_ms() clock_gettime_ms(CLOCK_REALTIME)
long clock_gettime_ms(clockid_t __clock_id);

#define gettime_microseconds() clock_gettime_microseconds(CLOCK_REALTIME)
long clock_gettime_microseconds(clockid_t __clock_id);

#endif /* time_util_h */
