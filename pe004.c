#include <stdio.h>

/* PROBLEM:

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

int max(int a, int b) {
    return a > b?a:b;
}

int isPalindrome(int n) {

    char s[7];
    sprintf(s, "%d", n);
    char * head = s;
    char * tail = s;
    while(*(tail + 1)) ++tail;
    while(head < tail) {
        if(*head != *tail) return 0;
        head++;
        tail--;
    }
    return 1;
}

int main() {

    int answer = 0;
    int i,j;
    for(i=100; i < 1000; ++i)
    for(j=i; j <1000; ++j) {
        int p = i * j;
        if(isPalindrome(p)) {
            answer = max(p, answer);
        }
    }
    if(!answer) return 1;

    printf("%d\n", answer);
    return 0;
}
