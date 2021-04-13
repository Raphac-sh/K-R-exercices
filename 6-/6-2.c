#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define TAILLETAMP 100

char *types[] = {
    "int",
    "char",
    "void",
    "_Bool"
};
#define NTYPES (sizeof types / sizeof types[0])

char tamp[TAILLETAMP];
int ptamp = 0;

struct node {
    char *word;
    int same;
    struct node *left;
    struct node *right;
};

struct node *addtree(struct node *, int num, char *, int *found);
void showtree(struct node *);
int readword(char *, int);
char *dupstring(char *);

int main(int argc, char *argv[]) {
    struct node *root;
    char *prev;
    char word[MAXWORD];
    int found;

    root = NULL;

    int num = (argc > 1 && (*++argv)[0] == '-') ? atoi(argv[0]+1) : 6;

    while(readword(word, MAXWORD) != EOF) {
        int isVar = 0;
        for(int i = 0; i < NTYPES; i++) {
            if(strcmp(types[i], prev) == 0) isVar = 1;
        }

        if(isalpha(word[0]) && strlen(word) > num && isVar)
            root = addtree(root, num, word, &found);
        found = 0;
        prev = dupstring(word);
    }
    showtree(root);

    return 0; 
}

struct node *allocatenode(void);
int readword(char *word, int lim);
int readcar(void);
void pushcar(int c); 
int comp(char *s, struct node *p, int num, int *found);

struct node *addtree(struct node *p, int num, char *w, int *found) {
    int cond;
    
    if(p == NULL) {
        p = allocatenode();
        p->word = dupstring(w);
        p->same = *found;
        p->left = p->right = NULL;
    } else if((cond = comp(w, p, num, found)) < 0) p->left = addtree(p->left, num, w, found);
    else p->right = addtree(p->right, num, w, found);

    return p;
}

int comp(char *s, struct node *p, int num, int *found) {
    int i;
    char *t = p->word;

    for(i = 0; *s++ == *t++; i++)
        if(*s == '\0') return 0;

    if(i > num) {
        *found = 1;
        p->same = 1;
    }

    return *s - *t;
}

void showtree(struct node *p) {
    if(p != NULL) {
        showtree(p->left);
        if(p->same) printf("%s\n", p->word);
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
	return (ptamp > 0) ? tamp[--ptamp] : getchar();
}

void pushcar(int c) {
	if(ptamp >= TAILLETAMP) {
		printf("pushcar: trop de caractères");
	} else {
		tamp[ptamp++] = c;
	}
}
