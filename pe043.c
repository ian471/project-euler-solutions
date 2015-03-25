/* PROBLEM #43:
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.
Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.
*/

#include <stdio.h>

/* 10! */
#define NUMPD 3628800

long nth_09_pandigital(int n) {
    if(n >= NUMPD) return -1;
    int total = NUMPD;
    int d = n;
    int digits_used = 0; /* bitmap */
    long r = 0;
    int i;
    for(i=0; i<10; ++i) {
        total /= 10 - i;
        int g = -1;
        while(digits_used & (1 << ++g));
        while(d >= total) {
            d -= total;
            while(digits_used & (1 << ++g));
        }
        digits_used |= 1 << g;
        r = 10*r + g;
    }
    return r;
}

int digits3(long n, int i) {
    int s = 8 - i;
    while(s-- > 0) {
        n /= 10;
    }
    return n % 1000;
}

int main() {
    
    int div[] = {1, 1, 2, 3, 5, 7, 11, 13, 17};

    long answer = 0;
    
    int i;
    for(i=NUMPD/10; i<NUMPD; ++i) {
        long p = nth_09_pandigital(i);
        int j;
        for(j=8; j>=2; --j) {
            int d = digits3(p, j);
            if(d % div[j]) break;
        }
        if(j < 2) {
            answer += p;
        }
    }

    printf("%ld\n", answer);
    return 0;
}
