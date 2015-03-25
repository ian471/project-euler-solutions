/* PROBLEM #35:
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
How many circular primes are there below one million?
*/

#include <stdio.h>

#define N 1000000

#define PRIME 1
#define CIRCULAR 2

void sieve(int *p, int n) {
    int i;
    p[0] = p[1] = 0;
    for(i=2; i<n; ++i) {
        p[i] = PRIME;
    }
    int m = 2;
    while(m < n/2) {
        if(p[m]) {
            int i;
            for(i=2*m; i<n; i+=m) {
                p[i] &= ~PRIME;
            }
        }
        m++;
    }
}

int nextRotation(int x) {
    int d = x;
    int e = 1;
    while(d > 9) {
        if(!(d % 10)) return 0;
        d /= 10;
        e *= 10;
    }
    return x * 10 - e * d * 10 + d;
}

int main() {

    int primes[N];
    sieve(primes, N);
    
    int i;
    for(i=2; i<N; ++i) {
        if(primes[i] & PRIME) {
            int j = nextRotation(i);
            int circular = 1;
            while(j != i) {
                if(!primes[j] & PRIME) {
                    circular = 0;
                    break;
                }
                j = nextRotation(j);
            }
            if(circular) {
                primes[i] |= CIRCULAR;
            }
        }
    }

    int count = 0;
    for(i=0; i<N; ++i) count += (primes[i] & CIRCULAR) ? 1 : 0;
    
    int answer = count;

    printf("%d\n", answer);
    return 0;
}
