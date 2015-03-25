/* PROBLEM #41:
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
What is the largest n-digit pandigital prime that exists?
*/

#include <stdio.h>

#include "func.h"
#define isprime(n) naive_prime_test(n)

#define NUMPD 409114

int nth_pandigital(int n) {
    if(n >= NUMPD) return -1;
    int d = n;
    int digits = 0;
    int total = 1;  /* equal to digits! */
    while(d >= total) {
        d -= total;
        ++digits;
        total *= digits;
    }
    /* we now want the dth pandigital with this number of digits */
    /* there are (total) pandigitals with (digits) digits */
    int digits_used = 0; /* bitmap */
    int r = 0;
    int i;
    for(i=0; i<digits; ++i) {
        total /= digits - i;
        int g = 0;
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

int main() {

    int i, p;
    for(i=NUMPD-1; i>=0; --i) {
        p = nth_pandigital(i);
        if(isprime(p)) break;
    }

    int answer = p;
    
    printf("%d\n", answer);
    return 0;
}
