/* not completly working */

#include <stdio.h>

#define MAXLENGTH 1000
#define LIMIT 5

int readLine(char *line, int maxLength);

int main(void)
{
    char line[MAXLENGTH];
    int length;

    int n = 1;
    int index;

    while((length = readLine(line, MAXLENGTH))) {
        while(length > LIMIT * n) {
            index = LIMIT * n + (n - 1);

            for(int i = length; i > index; i--) {
                line[i] = line[i-1];
            }

            line[index] = '\n';
            n++;
        }
        printf("%s", line);
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
