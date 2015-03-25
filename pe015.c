/* PROBLEM #15:
Starting in the top left corner of a 22 grid, there are 6 routes (without backtracking) to the bottom right corner.



How many routes are there through a 2020 grid?
*/

#include <stdio.h>
#define W 20
#define H 20

int main() {

    unsigned long r[W+1][H+1];
    
    int w, h;
    for(w=0; w<=W; ++w)
    for(h=0; h<=H; ++h) {
        if(!w || !h) r[w][h] = 1;
        else {
            r[w][h] = r[w-1][h] + r[w][h-1];
        }
    }
    
    unsigned long answer = r[W][H];

    printf("%lu\n", answer);
    return 0;
}
