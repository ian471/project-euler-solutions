/* PROBLEM #38:
Take the number 192 and multiply it by each of 1, 2, and 3:
192  1 = 192
192  2 = 384
192  3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n  1?
*/

#include <stdio.h>

#include "func.h"

int main() {

    int answer = 0;

    int n=192;
    while(n <= 10000) {
        
        /* result of the concatenation */
        int p = 0;
        
        /* bitmap for digits 0-9 */
        int digits = 0;
        
        /* element of the vector */
        int i = 1;
        
        /* boolean - is n pandigital? */
        int pandigital = 1;
        
        /* increment i until we get a pandigital or repeat a digit */
        while(pandigital && digits != (1 << 10) - 2) {
            int x = n*i;
            p = concatenate(p, x);
            
            /* mark each digit of the ith product */
            while(x) {
                if(x % 10 == 0 || digits & (1 << (x % 10))) {
                    /* zero or repeated digit */
                    pandigital = 0;
                    break;
                }
                digits |= (1 << (x % 10));
                x /= 10;
            }
            ++i;
        }
        if(pandigital) {
            /* keep the max pandigital */
            answer = p > answer ? p : answer;
        }
        ++n;
    }

    printf("%d\n", answer);
    return 0;
}
