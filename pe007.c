#include <stdio.h>

/* PROBLEM:

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

*/

#define P 10001

int main() {

    int p[P];
    
    int n = 2;
    int i, j;
    for(i=0; i<P; ++i) {
        for(j=0; j<i; ++j) {
            if(!(n % p[j])) {
                ++n;
                j = -1;
            }
        }
        p[i] = n++;
    }
    int answer = p[P-1];

    printf("%d\n", answer);
    return 0;
    
}
