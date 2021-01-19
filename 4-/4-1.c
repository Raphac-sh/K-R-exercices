#include <stdio.h>
#include <string.h>

int chposd(char s[], char t[]);
int readLine(char line[], int max);

int main(void) {
	char s[1000];
	char t[1000];

	while(readLine(s, 1000) != 0 && readLine(t, 1000) != 0) {
		printf("%d\n", chposd(s, t));
	}
}

int chposd(char s[], char t[]) {
	for(int i = strlen(s)-1; s[i] != '\0'; i--) {
		int j, k;
		for(j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++);
		
		printf("k : %d; j : %d; i : %d; t[k] : %c\n", k, j, i, t[k]);

		if(k > 0 && (t[k] == '\n' || t[k] == '\0')) {
			return i;	
		}
	}
	return -1;
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
