#include <stdio.h>

#define MAXLENGTH 1000

int readLine(char *line, int maxLength);
void reverse(char line[], int max);
void copy(char to[], char from[]);

int main(void)
{
    int length;
    char line[MAXLENGTH];

    while((length = readLine(line, MAXLENGTH))) {
        reverse(line, length);
        printf("%s", line);
    }

    return 0;
}

int readLine(char line[], int max) {
    char c;
    int i;

    for(i = 0; i < max-1 && (c = getchar()) != EOF; ++i) line[i] = c;

    return i;
}

void reverse(char line[], int max) {
    char s[MAXLENGTH];
    char c;
    int i, j;
    j = 0;

    for(i = max-1; i >= 0; --i) {
        s[j] = line[i];
        ++j;
    }
    s[j] = '\n';
    s[j+1] = '\0';


    copy(line, s);
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}