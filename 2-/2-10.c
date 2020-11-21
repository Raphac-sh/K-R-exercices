#include <stdio.h>

int min(char c);

int main(void) {
	char c;
	while((c = getchar()) != EOF) {
		printf("%c", min(c));
	}
}

int min(char c) {
	return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c; 
}
