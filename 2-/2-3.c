#include <stdio.h>

#define MAXLENGTH 1000

int readLine(char *line, int maxLength);
int puiss(int a, int b);
unsigned int htoi(char s[], int length);

int main(void)
{
    int length;
    char line[MAXLENGTH];
	int result;

	while((length = readLine(line, MAXLENGTH))) {
		result = htoi(line, length);
		printf("%d", result);
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

unsigned int htoi(char s[], int length) { 
	int result = 0;
	int n = length - 2;

	for(int i = 0; i < length; i++) {
		if(i == 0 && s[i] == 0 && (s[i + 1] == 'x' || s[i + 1] == 'X')) {
			continue;
		}
		else if(s[i] >= '0' && s[i] <= '9') {
			result += (s[i] - '0') * puiss(16, n); 
		}
		else if(s[i] >= 'a' && s[i] <= 'f') {
			result += (s[i] - 'a' + 10) * puiss(16, n);
		}
		else if(s[i] >= 'A' && s[i] <= 'F') {
			result += (s[i] - 'A' + 10) * puiss(16, n);
		}
		n--;
	}
	return result;
}

int puiss(int a, int b) {
	if(b == 0) return 1;
	int result = a;
	for(int i = 1; i < b; i++) {
		result = result * a;
	}
	return result;
}
