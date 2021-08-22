#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c;

    while((c = getchar()) != EOF) {
        if(iscntrl(c)) {
            if(c == '\n') putchar('\n');
            else printf("\\%x", c); 
        } else {
            putchar(c);
        }
    }

    return 0;
}
