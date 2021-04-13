#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLEX 100
#define TAILLETAMP 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dclabs(void);

int readlex(void);
int typelex;
char lex[MAXLEX];
char name[MAXLEX];
char type[MAXLEX];
char out[100];

char tamp[TAILLETAMP];
int ptamp = 0;

int main(void) {
    int pointer = 0;
    int type;
    char temp[MAXLEX];

    while(readlex() != EOF) {
        strcpy(out, lex);
        while((type = readlex()) != '\n') {
            if(type == PARENS || type == BRACKETS) {
                if(pointer) {
                    sprintf(temp, "(*%s)", out);
                    strcpy(out, temp); 
                    pointer = 0;
                }
                strcat(out, lex);
            } else if(type == '*') {
                pointer = 1;
            } else if(type == NAME) {
                if(pointer) {
                    sprintf(temp, "*%s", out);
                    strcpy(out, temp); 
                    pointer = 0;
                }
                sprintf(temp, "%s %s", lex, out);
                strcpy(out, temp);
            } else printf("incorrect input till %s\n", lex);
        }
        printf("%s\n", out);
    }

    return 0;
}

int readlex(void) {
    int c, readcar(void);
    void putcar(int);
    char *p = lex;

    while((c = readcar()) == ' ' || c == '\t');

    if(c == '(') {
        if((c = readcar()) == ')') {
            strcpy(lex, "()");
            return typelex = PARENS;
        } else {
            putcar(c);
            return typelex = '(';
        }
    } else if(c == '[') {
        for(*p++ = c; (*p++ = readcar()) != ']' && *(p-1) != '\n'; );
        if(*(p-1) == '\n') {
            printf("Error : missing closing brackets\n");
            return '\n';
        }

        *p = '\0';
        return typelex = BRACKETS;
    } else if(isalpha(c)) {
        for(*p++ = c; isalnum(c = readcar()); ) *p++ = c;
        *p = '\0';
        putcar(c);
        return typelex = NAME;
    } else return typelex = c;
}

void dcl(void) {
    int ne;
    for(ne = 0; readlex() == '*'; ) {
        ne++;
    }

    dclabs();

    while(ne-- > 0) strcat(out, " pointeur sur");
}

void dclabs(void) {
    int type;

    if(typelex == '(') {
        dcl();
        if(typelex != ')') printf("Error : ')' missing\n");
    } else if(typelex == NAME) {
        strcpy(name, lex);
    } else printf("Error : assuming to have a name or (dcl)\n");

    while((type = readlex()) == PARENS || type == BRACKETS) {
        if(type == PARENS) {
            strcat(out, " fonction retournant");
        } else {
            strcat(out, " tableau");
            strcat(out, lex);
            strcat(out, " de");
        }
    }
}


int readcar(void) {
	return (ptamp > 0) ? tamp[--ptamp] : getchar();
}

void putcar(int c) {
	if(ptamp >= TAILLETAMP) {
		printf("remettrecar: trop de caractères");
	} else {
		tamp[ptamp++] = c;
	}
}
