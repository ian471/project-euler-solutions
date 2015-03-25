/* PROBLEM #14:
The following iterative sequence is defined for the set of positive integers:
n  n/2 (n is even)
n  3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
13  40  20  10  5  16  8  4  2  1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <stdlib.h>
#include <stdio.h>

#define N 1000000
#define nextTerm(n) (n & 1 ? 3 * n + 1 : n >> 1)

int numTerms(int n) {
    
    int chainlen = 1;
    unsigned long m = n;
    
    while(m > 1) {
        ++chainlen;
        m = nextTerm(m);

    }
    
    return chainlen;
}


int main() {
    
    int maxchain = 0;
    int maxnum = 0;
    int i;
    for(i=1; i<N; ++i) {
        int m = numTerms(i);
        if(m == maxchain) {
            printf("%d ties at %d\n",i,m);
        }
        if(m > maxchain) {
            maxchain = m;
            maxnum = i;
        }
    }
    
    int answer = maxnum;
    
    printf("max chain length of %d\n", maxchain);

    printf("%d\n", answer);
    
    return 0;
}
