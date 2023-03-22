#include <stdio.h>
#include "c_challenges.h"
#include <stdint.h>

#define SMASK(x, y) (((uint8_t) ((1 << (x)) - 1) | (uint8_t) (1 << (x))) ^ (uint8_t) ((1 << (y)) - 1))
#define MASK(x) ((unsigned char) (1 << (x)))

typedef union{
struct {
    unsigned sunday: 1;
    unsigned monday: 1;
    unsigned tuesday: 1;
    unsigned wednesday: 1;
    unsigned thursday: 1;
    unsigned friday: 1;
    unsigned saturday: 1;
} days;
uint8_t byte_sized;
} weekdays;

int main() {
//    printf("racecar is palindrom: %s", Palindrom("racecar", 7)?"yes":"no");
//    fizbuzz();
//    matrixMul();
//    primeNums();
//    int a[8] = {1, 7, 2, 0, 2, -2, 4, 5};
//    merge_sort(a, 8);
//    for(int i = 0; i<8; i++){
//        printf("%d ", a[i]);
//    }
//
//    printf("\n7 is at index: %d\n", binary_search(a, 8, 7));
//    int n = 79536;
//    int m = reverse_bits_3(n, 8, 0);
//    printbits(sizeof(int), &n);
//    printbits(sizeof(int), &m);
    uint32_t mask = SMASK(6, 2);
    printbits(sizeof(uint8_t), &mask);

    weekdays active_days;
    active_days.days.friday = 1;
    active_days.days.saturday = 1;
    active_days.days.monday = 1;
    active_days.days.wednesday = 1;
    active_days.byte_sized &= ~(MASK(0) | MASK(2) | MASK(4));
    printbits(sizeof(uint8_t), &active_days.byte_sized);
    return 0;
}


