/* PROBLEM #21:
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a  b, then a and b are an amicable pair and each of a and b are called amicable numbers.
For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
Evaluate the sum of all the amicable numbers under 10000.
*/

#include <stdio.h>

#define N 10000

int main() {

    int d[N];
    
    int i;
    for(i=1; i<N; ++i) d[i] = 1;
    
    int stop = (N-1)/2;
    int f;
    for(f=2; f<=stop; ++f)
        for(i=2*f; i<N; i+=f)
            d[i] += f;
    
    int total = 0;
    for(i=1; i<N-1; ++i) {
        if(d[i] > i &&
           d[i] < N &&
           d[d[i]] == i
        )
            total += i + d[i];
    }
    
    int answer = total;

    printf("%d\n", answer);
    return 0;
}
