#include <stdio.h>

#define MAXLENGTH 1000

int readLine(char *line, int maxLength);

int main(void)
{
    int length;
    char line[MAXLENGTH];

    while((length = readLine(line, MAXLENGTH))) {
		printf("%s", line);
    }

    return 0;
}

int readLine(char line[], int max) {
    char c;
    int i;

    for(i = 0; ((i < max-1) == ((c = getchar()) != EOF) == (c != '\n')) == 1; ++i) line[i] = c;

    if(c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}
