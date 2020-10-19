#include <stdio.h>

#define ALPHABET 26

int main(void)
{
    char c = 0;
    int characters[ALPHABET];

    for (int i = 0; i < ALPHABET; ++i) {
        characters[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        ++characters[c - 'a'];
        ++characters[c - 'A'];

    }


    int max = 0;
    for(int i = 0; i < ALPHABET; ++i) {
        if(characters[i] >= max)
            max = characters[i];
    }

    putchar('\n');
    for(int i = max; i > 0; --i) {
        printf("%3d | ", i);
        for(int j = 0; j < ALPHABET; j++) {
            if(characters[j] >= i) {
                putchar('*');
            }
            else {
                putchar('-');
            }
        }
        putchar('\n');
    }

    printf("      __________________________\n      ");
    for(int i = 0; i < ALPHABET; ++i) {
        printf("%c", 'a' + i);
    }



    return 0;

}