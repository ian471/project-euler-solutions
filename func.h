#include <math.h>

/* Returns the smallest power of 10 that is larger than n */
int min10power(int n) {
    int m = 1;
    while(n) {
        n /= 10;
        m *= 10;
    }
    return m;
}

/* Concatenates the digits of a and b */
int concatenate(int a, int b) {
    return a * min10power(b) + b;
}

/* Returns the number of digits in the argument (decimal)
   Zero has 0 digits. */
int num_digits(int n) {
    int r = 0;
    while(n) {
        n /= 10;
        ++r;
    }
    return r;
}

int nth_digit(int d, int num) {
    int nd = num_digits(num);
    int i;
    for(i=0; i<nd-d; ++i) num /= 10;
    return num % 10;
}

int naive_prime_test(unsigned long n) {
    unsigned long i;
    unsigned long stop = sqrt(n);
    for(i=2; i<=stop; ++i) {
        if(!(n % i)) return 0;
    }
    return 1;
}
