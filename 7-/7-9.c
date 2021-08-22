#include <stdio.h>

#define ISUPPER(c) ((c) >= 'A' && (c) <= 'Z') ? 1 : 0

int isUpper(int c);

int main(void) {
    printf("%d, %c", isUpper('l'), 'l');
    printf("%d, %c", ISUPPER('Y'), 'Y');
}

int isUpper(int c) {
    if(c >= 'A' && c <= 'Z') return 1;
    else return 0;
}
