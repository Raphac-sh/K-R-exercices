#include <stdio.h>

#define MAXLENGTH 1000
#define LIMIT 5

int readLine(char *line, int maxLength);

int main(void)
{
    char line[MAXLENGTH];
    char finalLine[MAXLENGTH];
    int length;
    int n = 0;

    _Bool comment = 0;

    /* foiuhfdofh */

    while((length = readLine(line, MAXLENGTH))) {
        for(int i = 0; i < length; i++) {
            if (comment == 1) {
                if (line[i] == '*' && line[i + 1] == '/') {
                    comment = 0;
                    i++;
                }
            } else {
                if (line[i] == '/' && line[i + 1] == '*')  {
                    comment = 1;
                    i++;
                }
                else {
                    finalLine[n] = line[i];
                    n++;
                }
            }
        }
        printf("%s", finalLine);
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



