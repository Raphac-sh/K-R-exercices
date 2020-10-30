#include <stdio.h>

#define MAXLENGTH 1000

int readLine(char line[], int maxLength);
int tasser(char s1[], char s2[]); 

int main(void)
{
    int length1;
    char line1[MAXLENGTH];

    int length2;
    char line2[MAXLENGTH];

	while((length1 = readLine(line1, MAXLENGTH)) && (length2 = readLine(line2, MAXLENGTH))) {
		printf("%d", tasser(line1, line2));
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

int tasser(char s1[], char s2[]) {
	int i, j, k;
	char c;
	
	k= 0;
	while((c = s2[k]) != '\0') {
		for(i = j = 0; s1[j] != '\0'; i++) {
			if(s1[i] == c) {
				return i;
			}
		}	
		++k;
	}
	return -1;
}	
