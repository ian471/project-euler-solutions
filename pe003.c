#include <stdio.h>

/* PROBLEM:

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#define N 600851475143

int main() {

    long n = N;
    long f = 2;
    while(n > 1) {
        if(!(n % f)) {
            n /= f;
        } else {
            f++;
        }
    }
    long answer = f;

    printf("%d\n",answer);
    return 0;
}
