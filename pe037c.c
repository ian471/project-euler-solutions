/* PROBLEM #37:
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

#include <stdio.h>
#include <stdlib.h>

#include "sieve.h"

#define limit 200000000

short *p;
#define isprime(n) (p[n])

typedef unsigned long number;

/* return the smallest power of 10 that is greater than n */
number min10power(number n) {
    number m = 1;
    while(n) {
        n /= 10;
        m *= 10;
    }
    return m;
}

/* maps integers to integers containing only digits 3 7 and 9. */
number map379(number n) {
    int digits[] = {3, 7, 9};
    number r = 0;
    while(n) {
        r = r*10 + digits[n % 3];
        n /= 3;
    }
    return r;
}

int main() {
    p = malloc(limit * sizeof(short));
    sieve(p, limit);
    
    printf("Done generating primes.\n");
    
    number n = 0;
    number i = 2;
    while(1) {
        n = map379(++i);
        if(n >= limit) break;
        
        short lrtrunc = 1;
        
        number x = n;
        while(x >= 9) {
            if(!isprime(x)) {
                lrtrunc = 0;
                break;
            }
            x /= 10;
        }
        if(!lrtrunc) continue;
        
        number m = min10power(n);
        x = n;
        while(x >= 9) {
            if(!isprime(x)) {
                lrtrunc = 0;
                break;
            }
            m /= 10;
            x = x % m;
        }
        if(!lrtrunc) continue;
        
        printf("%d\n", n);
    }
    
/*    printf("%d\n", answer);*/
    return 0;
}
