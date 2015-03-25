/* PROBLEM #50:
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.
The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/

#include <stdio.h>
#include <stdlib.h>

#include "sieve.h"

#define N 1000000
#define isprime(n) (p[n])

int main() {

    short *p;
    p = malloc(N * sizeof(*p));
    sieve(p, N);
    
    int maxlen = 0;
    int maxprime = 2;
    
    int first = 3;
    int last = first;
    int sum = first;
    int len = 1;
    while(first < N / 2) {
        while(sum < N) {
            if(isprime(sum)) {
                if(len > maxlen) {
                    maxlen = len;
                    maxprime = sum;
                }
            }
            ++len;
            while(!isprime(last += 2));
            sum += last;
        }
        while(!isprime(first += 2));
        last = first;
        sum = first;
        len = 1;
    }
    
    int answer = maxprime;

    printf("%d\n", answer);
    
    free(p);
    
    return 0;
}
