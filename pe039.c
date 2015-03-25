/* PROBLEM #39:
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p <= 1000, is the number of solutions maximised?
*/

#include <stdio.h>
#include <math.h>
        
#define N 1000

int main() {

    int solns[N+1];
    int i;
    for(i=0; i<N+1; ++i) solns[i] = 0;
    
    int a, b;
    for(a=4; a < N/2; ++a) {
        for(b=1; b <= a; ++b) {
            float c = sqrt(a*a + b*b);
            if(c != (int) c) continue;
            int p = a + b + (int) c;
            if(p > N) break;
            ++solns[p];
        }
    }
    
    int answer = 0;
    int maxsolns = 0;
    for(i=12; i < N; ++i) {
        if(solns[i] > maxsolns) {
            answer = i;
            maxsolns = solns[i];
        }
    }
    
    printf("%d\n", answer);
    return 0;
}
