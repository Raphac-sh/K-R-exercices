#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLENGTH 10

int main(void)
{
    char c = 0;
    int state, n, max;
    int lengths[MAXLENGTH];

    for (int i = 0; i < MAXLENGTH; ++i) {
        lengths[i] = 0;
    }

    state = OUT;
    n = 0;

    while ((c = getchar()) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t') {
            if(n >= 1) {
                lengths[n - 1] += 1;
            }

            n = 0;
            state = OUT;
        }
        else {
            if(state == OUT) {
                state = IN;
            }
            n++;
        }
    }

    max = 0;
    for(int i = 0; i < MAXLENGTH; ++i) {
        if(lengths[i] >= max)
            max = lengths[i];
    }

    putchar('\n');
    for(int i = max; i > 0; --i) {
        printf("%3d | ", i);
        for(int j = 0; j < MAXLENGTH; j++) {
            if(lengths[j] >= i) {
                putchar('#');
            }
            else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    printf("    +------------\n      ");
    for(int i = 1; i <= MAXLENGTH; ++i) {
        printf("%d", i);
    }
    
    return 0;
}
