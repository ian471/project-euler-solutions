#include <stdio.h>

/* PROBLEM:

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

int main() {

    int n = 0;
    int f = 11;
    while(f < 20) {
        n += 20;
        for(f=11; f<20; ++f)
            if(n % f) break;
    }
    int answer = n;

    printf("%d\n", answer);
    return 0;
}
