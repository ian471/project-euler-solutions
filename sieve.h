#include <math.h>

void sieve(short *p, unsigned long n) {
    int i;
    p[0] = p[1] = 0;
    for(i=2; i<n; ++i) {
        p[i] = 1;
    }
    int m = 2;
    while(m <= sqrt(n)) {
        if(p[m]) {
            int i;
            for(i=2*m; i<n; i+=m) {
                p[i] = 0;
            }
        }
        m++;
    }
}
