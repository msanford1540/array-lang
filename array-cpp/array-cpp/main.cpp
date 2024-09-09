//
//  main.cpp
//  array-cpp
//
//  Created by Michael Sanford on 3/22/18.
//  Copyright © 2018 flipside5. All rights reserved.
//

#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;

#define xassert(cond) ( (cond) ? 0 : (perror("assert failure"), exit(1), -1) )

void array_test(int count) {
    std::vector<int> array(0);
    for (int i = 0; i < count; i++) {
        array.push_back(i);
    }
    xassert(array.size() == count);
    for (int i = 0; i < count; i++) {
        xassert(array[i] == i);
    }
    array.erase(array.begin(), array.begin()+count);
    xassert(array.size() == 0);
}

void show_test(int pass, int count) {
    printf("%d: [starting] steps=%d\n", pass, count);
    unsigned long startMicroseconds = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    array_test(count);
    unsigned long endMicroseconds = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    unsigned long durationInMicroseconds = endMicroseconds - startMicroseconds;
    float duratinInMilliseconds = (float)durationInMicroseconds / 1000.0;

    printf("%d: [done] time=%.3f ms\n\n", pass, duratinInMilliseconds);
}

int main(int argc, const char * argv[]) {
    int steps = 1000000;
    int passes = 2;
    
    printf("C++\n");
    for (int i = 0; i < passes; i++) {
        show_test(i, steps);
    }
    return 0;
}
