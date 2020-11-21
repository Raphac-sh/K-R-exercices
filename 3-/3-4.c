#include <stdio.h>
#include <string.h>
#include <limits.h> 

#define abs(x) ((x < 0) ? -x : x)

void itoa(int n, char s[]);
void reverse(char s[]);
int readline(char line[], int max);

int main(void) {
	char s[1000];
	itoa(INT_MIN, s);

	printf("%s", s);
}

void reverse(char s[]) {
	int c, i, j;

	for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[]) {
	int i, sign;

	sign = n;

	i = 0;

	do {
		s[i++] = abs((n % 10)) + '0';
	} while ((n /= 10) != 0);

	if(sign < 0) s[i++] = '-';

	s[i] = '\0';
	reverse(s);
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
