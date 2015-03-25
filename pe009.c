#include <stdio.h>

/* PROBLEM:

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*/

int main() {

    int a = 1;
    int b,c;
    
    while(1) {
        while((1000 * (a - 500)) % (a - 1000) && a < 498) a++;

        b = (1000 * (a - 500)) / (a - 1000);
        c = 1000 - a - b;
        
        if(0 < a < b < c) break;
        if(a >= 498) {
            printf("Not found.\n");
            return 1;
        }
        a++;
        
    }
    int answer = a*b*c;

    printf("%d\n", answer);
    return 0;
    
}
