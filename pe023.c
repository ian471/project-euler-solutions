/* PROBLEM #23:
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <stdio.h>
#include "list.h"

#define N 28124

int main() {

    /* calculate d(n) for 0 < n < N */
    int d[N];
    
    int i;
    for(i=1; i<N; ++i) d[i] = 1;
    
    int stop = (N-1)/2;
    int f;
    for(f=2; f<=stop; ++f)
        for(i=2*f; i<N; i+=f)
            d[i] += f;
    
    /* list all abundant numbers in order low-high */
    list * empty = list_create_empty();
    list **abundant = &empty;
    for(i=N-1; i>0; --i) {
        if(d[i] > i) {
            list_push(abundant, i);
        }
    }
    
    /* try all combinations of abundant numbers */
    unsigned long total = N * (N - 1) / 2; /* 1+...+N-1 */
    list *a;
    list *b;
    
    /* DEBUG *//*
    for(a=*abundant; a; a=a->next) {
        printf("%d\t", a->val);
    }*/
    
    for(a=*abundant; a; a=a->next) {
        for(b=a; b; b=b->next) {
            int sum = a->val + b->val;
            if(sum >= N) break;
            if(d[sum]) {
                total -= sum;
                d[sum] = 0; /* mark sum as already found */
            }
        }
    }
    
    list_destroy(*abundant);

    printf("%lu\n", total);
    return 0;
}
