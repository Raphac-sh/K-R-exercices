#include <stdio.h>

#define MAXLENGTH 1000

void echap(char s[], char t[]);
void unEchap(char s[], char t[]);
int readLine(char line[], int max);

int main(void) {
	char line[MAXLENGTH];
	char ech[MAXLENGTH];
	int length;

	while((length = readLine(line, MAXLENGTH))) {
		unEchap(ech, line);
		printf("%s", ech); 
	}	
}

void echap(char s[], char t[]) {
	int i, j;

	for(i = j = 0; t[i] != '\0'; i++) {
		switch(t[i]) {
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;

			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;

			default:
				s[j++] = t[i];
				break;
	
		}
	}

	s[j] = '\0';
}

void unEchap(char s[], char t[]) {
	int i, j;

	for(i = j = 0; t[i] != '\0'; i++) {
		if(t[i] == '\\') {

			switch(t[++i]) {
				case 't':
					s[j++] = '\t';
					break;

				case 'n':
					s[j++] = '\n';
					break;

				default:
					s[j++] = t[i];
					break;
	
			}
		}
		else {
			s[j++] = t[i];
		}
	}

	s[j] = '\0';
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

