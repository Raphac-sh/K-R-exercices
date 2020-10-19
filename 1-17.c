#include <stdio.h>

#define MAXLENGTH 1000
#define LIMIT 80

int readLine(char *line, int maxLength);

int main(void)
{
    int length;
    char line[MAXLENGTH];

    while((length = readLine(line, MAXLENGTH))) {
        if(length > LIMIT) printf("%s", line);
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