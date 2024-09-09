//
//  main.m
//  array-objc
//
//  Created by Michael Sanford on 3/16/18.
//  Copyright © 2018 flipside5. All rights reserved.
//

#import <Foundation/Foundation.h>

#define xassert(cond) ( (cond) ? 0 : (perror("assert failure"), exit(1), -1) )

void arrayTest(NSInteger count) {
    NSMutableArray <NSNumber *> *buffer = [[NSMutableArray alloc] init];
    xassert(buffer.count == 0);
    for (int i = 0; i < count; i++) {
        [buffer addObject:@(i)];
    }
    xassert(buffer.count == count);
    for (int i = 0; i < count; i++) {
        xassert(buffer[i].intValue == i);
    }
    buffer = nil;
    xassert(buffer.count == 0);
}

void showTest(NSInteger pass, NSInteger count) {
    printf("%ld: [starting] steps=%ld\n", pass, count);
    NSDate *startTime = [[NSDate alloc] init];
    arrayTest(count);
    float durationInMS = startTime.timeIntervalSinceNow * -1000.0;
    printf("%ld: [done] time=%.3f ms\n\n", pass, durationInMS);
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSInteger steps = 1000000;
        NSInteger passes = 2;
        
        printf("Objective-C\n");
        for (int i = 0; i < passes; i++) {
            showTest(i, steps);
        }
    }
    return 0;
}
