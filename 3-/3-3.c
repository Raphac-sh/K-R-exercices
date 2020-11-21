#include <stdio.h>

int develop(char s1[], char s2[]);
int readLine(char line[], int max);

int main(void) {
	int length;
	char line[1000];
	char developped[1000];

	while((length = readLine(line, 1000))) {
		develop(developped, line);
		printf("%s", developped); 
	}
}

int develop(char s1[], char s2[]) {
	int i, j;
	char c;	
	j = i = 0;

	while((c = s2[i++]) != '\0') {
		if(s2[i] == '-' && s2[i+1] >= c) {
			while(c < s2[i+1]) {
				s1[j++] = c++;	
			}
		} else {
			s2[j++] = c;
		}

		s1[j] = '\0';
	}

	int l = 0;
	while(s1[l] != '\0') l++;

	return l;
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
