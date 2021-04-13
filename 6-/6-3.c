#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define TAILLETAMP 100

char tamp[TAILLETAMP];
int ptamp = 0;

struct node {
    char *word;
    struct node *left;
    struct node *right;
    int *lines;
};

struct node *addtree(struct node *,char *);
void showtree(struct node *);
int readword(char *, int);
char *dupstring(char *);

static int line = 1;

int main(int argc, char *argv[]) {
    struct node *root;
    char word[MAXWORD];
    int found;
    root = NULL;

    while(readword(word, MAXWORD) != EOF) {
        if(isalpha(word[0]))
            root = addtree(root, word);
        found = 0;
    }
    showtree(root);

    return 0; 
}

struct node *allocatenode(void);
int readword(char *word, int lim);
int readcar(void);
void pushcar(int c); 

struct node *addtree(struct node *p, char *w) {
    int cond;
    
    if(p == NULL) {
        p = allocatenode();
        p->word = dupstring(w);
        p->lines = malloc(100);
        *((p->lines)++) = line; 
        p->left = p->right = NULL;
    } else if((cond = strcmp(w, p->word)) == 0) *((p->lines)++) = line;
    else if(cond < 0) p->left = addtree(p->left, w);
    else p->right = addtree(p->right, w);

    return p;
}

void showtree(struct node *p) {
    if(p != NULL) {
        showtree(p->left);
        printf("%s", p->word);
        while(*(--p->lines)) printf(", %d", *((p->lines)));
        printf("\n");
        showtree(p->right);
    }
}

struct node *allocatenode(void) {
    return (struct node *) malloc(sizeof(struct node));
}

char *dupstring(char *s) {
    char *p;

    p = (char *) malloc(strlen(s)+1);
    if(p != NULL) strcpy(p, s);
    return p;
}

int readword(char *word, int lim) {
    int c, readcar(void);
    void pushcar(int);
    char *w = word;
    while(isspace(c = readcar()));

    if(c != EOF) *w++ = c;
    if(!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for( ; --lim > 0; w++) {
        if(!isalnum(*w = readcar())) {
            pushcar(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

int readcar(void) {
    if(ptamp > 0) {
        if(tamp[--ptamp] == '\n') line++;
        return tamp[--ptamp];
    }
    else {
        int c = getchar();
        if(c == '\n') line++;
        return c;
    }
}

void pushcar(int c) {
	if(ptamp >= TAILLETAMP) {
		printf("pushcar: trop de caractères");
	} else {
		tamp[ptamp++] = c;
	}
}
