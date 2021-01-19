#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int lire_op(char s[]) {
	int i, c;
    static int lastChar = 0;
    i = 0;

    if(lastChar == 0) {
        c = lirecar();
    } else {
        c = lastChar;
        lastChar = 0;
    }

	while((s[0] = c) == ' ' || c == '\t') c = lirecar();

	s[1] = '\0';

	if(islower(c)) {
		while (islower(s[++i] = c = lirecar()));

		s[i] = '\0';
		if(c != EOF) lastChar = c;
		if(strlen(s) > 1) return NOM;
		else return c;
	}

	if(!isdigit(c) && c != '.' && c != '-') return c;

	if(c == '-') {
		if(isdigit(c = lirecar()) || c == '.') s[++i] = c;
		else {
			if(c != EOF) lastChar = c;
			return '.';
		}
	}

	if(isdigit(c)) {
		while (isdigit(s[++i] = c = lirecar()));
	}

	if(c == '.') {
		while (isdigit(s[++i] = c = lirecar()));
	}

	if(c == 'e') {
		while (isdigit(s[++i] = c = lirecar()));
	}

	s[i] = '\0';

    if(c != EOF) {
        lastChar = c;
    }

	return NOMBRE;
}
