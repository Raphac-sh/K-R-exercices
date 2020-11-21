#include <stdio.h>

#define MAXLENGTH 1000

int deleteSpaces(char s[]); 
int readLine(char *line, int maxLength);

int main(void)
{
    int length;
    char line[MAXLENGTH];

    while((length = readLine(line, MAXLENGTH))) {
		if(deleteSpaces(line) > 0) {
			printf("%s", line);
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

int deleteSpaces(char s[]) {
	int i;

	i = 0;
	while(s[i] != '\n') ++i;

	for(i--; i >= 0 && (s[i] == ' ' || s[i] == '\t'); --i); 

	if(i >= 0) {
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}
	return i;
}
