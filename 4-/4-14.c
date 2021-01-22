#include <stdio.h>

#define exchange(t, x, y) { t z;\
    z = x;\
    x = y;\
    y = z; }

int main(void) {
    int x = 6;
    int y = 124;

    exchange(int, x, y);

    printf("x : %d; y : %d", x, y);

    return 0;
}
