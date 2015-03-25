#include <stdio.h>

/* PROBLEM:
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#define N 2000000

int main() {

    short p[N];
    
    unsigned long answer = 0;
    
    int i;
    for(i=0; i<N; ++i) {
        p[i] = 0;
    }
    
    for(i=2; i<N; ++i) {
        if(!p[i]) {
            int j;
            for(j=i; j<N; j+=i) {
                p[j] = (short) 1;
            }
/*            printf("%d\t", i);*/
            answer += i;
        }
    }

    printf("%li\n", answer);
    return 0;
}
