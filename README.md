# array-lang

This compares array performance across different language implementations. The array tests are based of the 'ion compiler' tests from bitwise (https://github.com/pervognsen/bitwise).

Note: The C "stretchy buffers" props go to Sean Barrett.

## Test
1. Inserts 1,000,000 integers into an array one at a time
2. Iterates over that array verfiying the integers are the expected values

## Performance Test Results on late 2016 15" MacBook Pro
 
| Language | Array Type | Pass 1 (ms) | Pass 2 (ms) |
|-|-|:-:|:-:|
| C | "stretchy buffers" | 7 | 7 |
| C++ | std::vector | 12 | 4 |
| Objective-C | NSArray | 76 | 47 |
| Swift 4.1 | non-optional | 18 | 6 |
| Swift 4.1 | forced optional | 20 | 8 |
| Swift 4.1 | unforced optional | 20 | 9 |

## Performance Test Results on 2021 M1 Max 14" MacBook Pro
| Language | Array Type | Pass 1 (ms) | Pass 2 (ms) |
|-|-|:-:|:-:|
| C | "stretchy buffers" | 3.43 | 3.43 |
| C++ | std::vector | 1.63 | 1.97 |
| Objective-C | NSArray | 39.85 | 37.74 |
| Swift 6.0 | non-optional | 4.13 | 4.05 |
| Swift 6.0 | forced optional | 5.13 | 4.93 |
| Swift 6.0 | unforced optional | 4.76 | 4.76 |
