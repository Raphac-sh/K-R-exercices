#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TAILLETAMP 100

char tamp[TAILLETAMP];
int ptamp = 0;

struct key {
    char *word;
    int cpt;
} tabkey[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

#define MAXWORD 100
#define NKEYS (sizeof tabkey / sizeof tabkey[0])

int readword(char *, int);
int dicho(char *, struct key *, int);
int readword(char *word, int lim);
int readcar(void);
void pushcar(int c); 

int main(void) {
    int n;
    char word[MAXWORD];

    while(readword(word, MAXWORD) != EOF) {
        if(isalpha(word[0]))
            if((n = dicho(word, tabkey, NKEYS)) >= 0)
                tabkey[n].cpt++;
    }
    for(n = 0; n < NKEYS; n++) {
        if(tabkey[n].cpt > 0)
            printf("%4d %s\n", tabkey[n].cpt, tabkey[n].word);
    }

    return 0;
}

int dicho(char *mot, struct key tab[], int n) {
    int cond;
    int bottom, top, middle;

    bottom = 0;
    top = n-1;
    while(bottom <= top) {
        middle = (bottom+top)/2;
        if((cond = strcmp(mot, tab[middle].word)) < 0)
            top = middle-1;
        else if (cond > 0)
            bottom = middle+1;
        else return middle;
    }

    return -1;
}

int readword(char *word, int lim) {
    int c, d;
    char *w = word;
    
    while(isspace(c = readcar()));

    if(c != EOF) *w++ = c;
    else return EOF;

    if(isalpha(c) || c == '_' || c == '#') {
        for( ; --lim > 0; w++) {
            if(!isalnum(*w = readcar()) && *w != '_') {
                pushcar(*w);
                break;
            }
        }
    } else if(c == '\'' || c == '"') {
        for( ; --lim > 0; w++) {
            if((*w = readcar()) == '\\') {
                *++w = readcar();
            } else if(*w == c) {
                w++;
                break;
            } else if(*w == EOF) {
                return EOF;
            }
        }
    } else if(c == '\\') {
        if((d = readcar()) == '*') {
            int e;

            while((e = readcar()) != EOF) {
                if(e == '*') {
                    if((e = readcar()) == '\\') {
                        break;
                    } else {
                        pushcar(e);
                    }
                }
            }
            if(e == EOF) return EOF;
        }
    }

    *w = '\0';
    return word[0];
}

int readcar(void) {
	return (ptamp > 0) ? tamp[--ptamp] : getchar();
}

void pushcar(int c) {
	if(ptamp >= TAILLETAMP) {
		printf("pushcar: trop de caractères");
	} else {
		tamp[ptamp++] = c;
	}
}
