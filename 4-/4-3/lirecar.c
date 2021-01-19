#include <stdio.h>
#include <string.h>
#include "calc.h"

#define TAILLETAMP 100

void remettrech(char s[]);

char tamp[TAILLETAMP];
int ptamp = 0;


int lirecar(void) {
	return (ptamp > 0) ? tamp[--ptamp] : getchar();
}

void remettrecar(int c) {
	if(ptamp >= TAILLETAMP) {
		printf("remettrecar: trop de caractères");
	} else {
		tamp[ptamp++] = c;
	}
}

void remettrech(char s[]) {
    int i = strlen(s);
    
    while((--i) >= 0) {
        remettrecar(s[i]); 
    }
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
