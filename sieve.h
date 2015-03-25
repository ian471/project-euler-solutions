#include <math.h>

/* Fill the array p[] of length n with 1 or 0, depending on whether
   each index is prime (1) or not. */
void sieve(short *p, unsigned long n) {
    int i;
    p[0] = p[1] = 0;
    for(i=2; i<n; ++i) {
        p[i] = 1;
    }
    int m;
    int stop = (int) sqrt(n);
    for(m=2; m<=stop; m+=2) {
        if(!p[m]) continue;
        int j;
        for(j=2*m; j<n; j+=m) {
            p[j] = 0;
        }
    }
}

int sieve_prime_test(unsigned long n) {
    short *p = malloc(sizeof short * (n + 1));
    sieve(p, n + 1);
    int result = p[n];
    free(p);
    return result;
}
