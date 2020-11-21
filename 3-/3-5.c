#include <stdio.h>
#include <string.h>
#include <limits.h> 

#define abs(x) ((x < 0) ? -x : x)

void itob(int n, char s[], int b);
void reverse(char s[]);
int readline(char line[], int max);

int main(void) {
	char s[1000];
itob(0, s, 60);

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

void itob(int n, char s[], int b) {
	int i, j, sign;

	if((sign = n) < 0) n = -n;

	i = 0;

	do {
		j = (n % b); 	
		s[i++] = j <= 9 ? j + '0' : (j < 35 ? j + 'a' - 10 : j + 'A' - 36);
	} while ((n /= b) != 0);

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
