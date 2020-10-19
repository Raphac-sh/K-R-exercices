#include <stdio.h>

#define MAXLENGTH 1000
#define LIMIT 80

int readLine(char *line, int maxLength);

int main(void)
{
    char line[MAXLENGTH];
    int tabSize = 4;

    int i, j;

    while(readLine(line, MAXLENGTH)) {
        for(i = 0; line[i] != '\0' ; i++) {
            if(line[i] == '\t') {
                for(j = 0; j < tabSize; j++) {
                    line[i + j] = ' ';
                }
            }

            putchar(line[i]);
        }
    }

    return 0;
}

int readLine(char line[], int max) {
    char c;
    int i;

    for(i = 0; i < max-1 && (c = getchar()) != EOF && c != '\n'; ++i) line[i] = c;

    if(c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}