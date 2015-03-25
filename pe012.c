/* PROBLEM #12:
The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
Let us list the factors of the first seven triangle numbers:
1: 1
3: 1,3
6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28
We can see that 28 is the first triangle number to have over five divisors.
What is the value of the first triangle number to have over five hundred divisors?
*/

#include <stdio.h>
#include <math.h>

#define N 500

int num_divisors(int n) {
    int count = 0;
    int i;
    int limit = ceil(sqrt(n));
    for(i=2; i<limit; ++i) {
        if(!(n % i)) ++count;
    }
    return count * 2 + 2;
}

int main() {

    int t;
    int n=0;
    for(t=1; 1; ++t) {
        n += t;
        int nd = num_divisors(n);
        /* printf("%d %d %d\n", t, n, nd); */
        if(nd > N) {
            break;
        }
    }
    int answer = n;

    printf("%d\n", answer);
    return 0;
}
