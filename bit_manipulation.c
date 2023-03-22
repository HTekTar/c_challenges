#include <stdio.h>
#include <stdint.h>

#define MASK(x) ((unsigned char) (1 << (x)))
#define MASK8(x) ((uint8_t) (1 << (x)))
#define MASK16(x) ((uint16_t) (1 << (x)))
#define MASK32(x) ((uint32_t ) (1 << (x)))




uint8_t PORTB = 0;

void setup(){
    uint8_t temp = PORTB;
    //set bit 2 and 5, clear bits 0, 3, and 7
    temp |= MASK(2) | MASK(5);
    temp &= ~(MASK(0) | MASK(3) | MASK(7));
//if bit 4 is high invert bit 1
    if(temp & MASK(4)) temp ^= MASK(1);
    PORTB = temp;
}

void printbits(size_t sz, const void *ptr){
    unsigned char *c = (unsigned char*) ptr;
    for(size_t i=0; i<sz; i++){
        unsigned char byte = *(c + sz - 1 - i);
        for(int j=7; j>=0; j--){
            printf("%c", (byte & (1 << j)) ? '1':'0');
        }
        printf(" ");
    }
    printf("\n");
}

int reverse_bits(int n){
    size_t l = 0, r = sizeof(int)*8 - 1;

    int ans = 0;
    while(l < r){
        int mask = (1<<r) | (1<<l);
        int m = n & mask;
        if(m == 0 | m == mask) ans |= m;
        else ans |= (m ^ mask);
        l++;
        r--;
    }
    return ans;
}
int reverse_bits_2(int n){
    size_t bits = sizeof(int) * 8;
    int ans = 0;
    for(size_t i=0; i<bits; i++){
        ans <<= 1;
        if(n & 1)  ans |= 1;
        n >>= 1;
    }
    return ans;
}

int reverse_bits_3(int n, size_t l, size_t r){
    if(l <= r) return n;
    size_t bits = sizeof(int) * 8;
    if(l >= bits) return n;
    n >>= r;
    int ans = 0;
    for(size_t i=0; i <= l-r; i++){
        ans <<= 1;
        if(n & 1) ans |= 1;
        n >>= 1;
    }
    ans <<= r;
    return ans;
}

