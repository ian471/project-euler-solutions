/* PROBLEM #26:
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:



1/2=0.5


1/3=0.(3)


1/4=0.25


1/5=0.2


1/6=0.1(6)


1/7=0.(142857)


1/8=0.125


1/9=0.(1)


1/10=0.1



Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
Find the value of d  1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

#include <stdio.h>

#define debug if(DEBUG)

#define N 1000
#define DEBUG 0

int looplen(int d) {
    int used[N] = {0};
    int n = 10;
    int i = 0;
    debug printf("1/%d = 0.", d);
    while(1) { /* 60 limit is for DEBUG */
        int digit = n / d;
        debug printf("%d", digit);
        int u = used[n / 10];
        if(u) {
            debug printf("\n\t%d-digit cycle\n", i - u);
            return i - u;
        }
        used[n / 10] = i;
        n = 10 * (n - d * digit);
        ++i;
    }
}

int main() {

    int maxlooplen = 0;
    int maxd = 0;

    int d;
    for(d=2; d<N; ++d) {
        int loop = looplen(d);
        if(loop > maxlooplen) {
            maxlooplen = loop;
            maxd = d;
        }
    }
    
    int answer = maxd;

    printf("%d\n", answer);
    return 0;
}
