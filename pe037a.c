/* PROBLEM #37:
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#include "sieve.h"

#define limit 200000000

short *p;
#define isprime(n) (p[n])

/* return the smallest power of 10 that is greater than n */
int min10power(int n) {
    int m = 1;
    while(n) {
        n /= 10;
        m *= 10;
    }
    return m;
}

void generate_left(list **l, int n) {
    if(n >= limit) return;
    if(!n || isprime(n)) {
        int m = min10power(n);
        if(n > 9)
            list_push(l, n);
        generate_left(l, m*3 + n);
        generate_left(l, m*7 + n);
        generate_left(l, m*9 + n);
    }
}

void generate_right(list **l, int n) {
    if(n >= limit) return;
    if(!n || isprime(n)) {
        if(n > 9)
            list_push(l, n);
        generate_right(l, 10*n + 3);
        generate_right(l, 10*n + 7);
        generate_right(l, 10*n + 9);
    }
}

int main() {

    p = malloc(limit * sizeof(short));
    sieve(p, limit);
    
    list *empty1 = list_create_empty();
    list *empty2 = list_create_empty();
    list **left = &empty1;
    list **right = &empty2;
    
    generate_left(left, 0);
    generate_right(right, 0);
    
    list* i;
    for(i=*left; i; i=i->next) {
        if(list_contains(*right, i->val)) {
            printf("%d\n", i->val);
        }
    }/*
    printf("\n");
    for(i=*right; i; i=i->next) {
        printf("%d ", i->val);
    }
    printf("\n");*/
    
    free(p);
    
    int answer = 0;

    /* printf("\nsum: %d\n", answer);*/
    return 0;
}
