/* PROBLEM #37:
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

#include <stdio.h>
#include <math.h>

#include "queue.h"
/*#include "sieve.h"*/

#define limit 739400


/*#define isprime(n) (p[n])*/
#define isprime(n) naive_prime_test(n)
/*short *p;*/

int naive_prime_test(unsigned long n) {
    unsigned long i;
    unsigned long stop = sqrt(n);
    for(i=2; i<=stop; ++i) {
        if(!(n % i)) return 0;
    }
    return 1;
}

int min10power(int n) {
    int m = 1;
    while(n) {
        n /= 10;
        m *= 10;
    }
    return m;
}

int left_add_digit(int n, int d) {
    return min10power(n)*d + n;
}

int right_add_digit(int n, int d) {
    return 10*n + d;
}

int main() {
/*
    p = malloc(limit * sizeof(short));
    sieve(p, limit);
  */  
    queue *q = queue_create();
    queue *left = queue_create();
    
    /* Build list of left-truncatable primes */
    queue_enqueue(q, 3);
    queue_enqueue(q, 7);
    queue_enqueue(q, 9);
    while(queue_length(q)) {
        int n = queue_dequeue(q);
        if(n < limit && isprime(n)) {
            queue_enqueue(left, n);
            queue_enqueue(q, left_add_digit(n, 1));
            queue_enqueue(q, left_add_digit(n, 2));
            queue_enqueue(q, left_add_digit(n, 3));
            queue_enqueue(q, left_add_digit(n, 5));
            queue_enqueue(q, left_add_digit(n, 7));
            queue_enqueue(q, left_add_digit(n, 9));
        }
    }
    
    int count = 0;
    int answer = 0;
    
    /* Find right-truncatable primes */
    queue_enqueue(q, 2);
    queue_enqueue(q, 3);
    queue_enqueue(q, 5);
    queue_enqueue(q, 7);
    queue_enqueue(q, 9);
    while(queue_length(q) && count < 11) {
        int n = queue_dequeue(q);
        if(n < limit && isprime(n)) {
            if(n > 9 && queue_contains(left, n)) {
/*                printf("\t%d\n", n);*/
                ++count;
                answer += n;
            }
            queue_enqueue(q, right_add_digit(n, 1));
            queue_enqueue(q, right_add_digit(n, 3));
            queue_enqueue(q, right_add_digit(n, 7));
            queue_enqueue(q, right_add_digit(n, 9));
        }
    }

    if(count != 11) {
        printf("Found %d\n", count);
        return 1;
    } else {
        printf("%d\n", answer);
    }
    return 0;
    
}
