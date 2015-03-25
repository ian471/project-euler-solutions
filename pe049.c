/* PROBLEM #49:
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
What 12-digit number do you form by concatenating the three terms in this sequence?
*/

#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"
#include "func.h"
#define isprime(n) (p[n])

#define MAXP 10000

void sortArray(int *a, int len) {
    /* bubble sort! */
    int i;
    for(i=0; i<len; ++i) {
        int j;
        for(j=0; j<len-i-1; ++j) {
            if(a[j] > a[j+1]) {
                int swap = a[j];
                a[j] = a[j+1];
                a[j+1] = swap;
            }
        }
    }
}

int nextPermutation(int n) {
    if(n < 10) return -1;
    int p = min10power(n / 10);
    int tail = n % p;
    int next = nextPermutation(tail);
    if(next >= 0) {
        return n - tail + next;
    }
    
    /* Increment the high-order digit and sort
       the tail low-high */
    int high = n / p;
    int len = numDigits(n);
    int *a = malloc(len * sizeof(int));
    int2array(n, a);
    sortArray(a, len);
    
    int i;
    for(i=0; i<len; ++i) {
        if(a[i] > high) break;
    }
    if(i >= len) return -1;
    int r = a[i] * p;
    int j;
    for(j=0; j<len; ++j) {
        if(j == i) continue;
        p /= 10;
        r += p*a[j];
    }
    free(a);
    return r;
}

int numDigits(int n) {
    int r = 0;
    while(n) {
        n /= 10;
        ++r;
    }
    return r;
}

int int2array(int n, int* a) {
    int len = 0;
    while(n) {
        *(a++) = n % 10;
        n /= 10;
        ++len;
    }
    return len;
}

int isPermutationOf(int n, int m) {
    int d[4];
    int i, j;
    for(i=0; i<4; ++i) {
        d[i] = m % 10;
        m /= 10;
    }
    for(i=0; i<4; ++i) {
        int g = n % 10;
        for(j=0; j<4; ++j) {
            if(g == d[j]) {
                d[j] = -1;
                break;
            }
        }
        if(j >= 4) return 0;
        n /= 10;
    }
    return 1;
}

long find4dSeq() {
    short *p;
    p = malloc(MAXP*sizeof(typeof(*p)));
    sieve(p, MAXP);

    int a, b, c, d;
    for(a=1; a<10; ++a)
    for(b=a; b<10; ++b)
    for(c=b; c<10; ++c)
    for(d=c; d<10; ++d) {
        int x = a*1000 + b*100 + c*10 + d;
        int first = 1;
        while(1) {
            if(!first) x = nextPermutation(x);
            first = 0;
            if(x < 0) break;
            if(!isprime(x)) continue;
            int y = x;
            while(1) {
                y = nextPermutation(y);
                if(y < 0) break;
                if(!isprime(y)) continue;
                int z = y + (y - x);
                if(z < 10000 && isprime(z) && isPermutationOf(z, x)) {
                    if(x != 1487) {
                        return concatenate(x, concatenate(y, z));
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    long answer = find4dSeq();

    printf("%ld\n", answer);
    return 0;
}
