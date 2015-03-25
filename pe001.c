#include <stdio.h>

int main() {
    int total = 0;
    int i;
    for(i=0; i<1000; i+=3) total += i;
    for(i=0; i<1000; i+=5) {
        if(i % 3) total += i;
    }
    printf("%d\n", total);
    return 0;
}
