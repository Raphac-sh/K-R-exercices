#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NOMBRE 0
#define MAX 100

int readLine(char line[], int max);

int li = 0;
char line[MAX];

int lire_op(char s[]) {
	int i, c;
    i = 0;

    if(line[li] == '\0') {
        if(readLine(line, MAX) == 0) {
            return EOF;
        } else {
            li = 0;
        }
    }

	while((s[0] = c = line[li++]) == ' ' || c == '\t');

	s[1] = '\0';

	if(islower(c)) {
		while (islower(s[++i] = c = line[li++]));

		s[i] = '\0';
		if(c != EOF) li--;
		if(strlen(s) > 1) return NOM;
		else return c;
	}

	if(!isdigit(c) && c != '.' && c != '-') return c;

	if(c == '-') {
		if(isdigit(c = line[li++]) || c == '.') s[++i] = c;
		else {
			if(c != EOF) li--;
			return '.';
		}
	}

	if(isdigit(c)) {
		while (isdigit(s[++i] = c = line[li++]));
	}

	if(c == '.') {
		while (isdigit(s[++i] = c = line[li++]));
	}

	if(c == 'e') {
		while (isdigit(s[++i] = c = line[li++]));
	}

	s[i] = '\0';


    if(c != EOF) {
        li--;
    }

	return NOMBRE;
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
