#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define TAILLETAMP 100
#define MAXLIST 100

char tamp[TAILLETAMP];
int ptamp = 0;

struct node {
    char *word;
    int cpt;
    struct node *left;
    struct node *right;
};

struct node *addtree(struct node *,char *);
int createList(struct node *p);
void sortlist(int left, int right);
int readword(char *, int);
char *dupstring(char *);

static struct node *list[MAXLIST];

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
    int num = createList(root);
    sortlist(0, num-1);

    for(int i = 0; i < num; i++) {
        printf("%s : %d\n", list[i]->word, list[i]->cpt);
    }

    return 0; 
}

struct node *allocatenode(void);
void exchange(int i, int j);
int readword(char *word, int lim);
int readcar(void);
void pushcar(int c); 

struct node *addtree(struct node *p, char *w) {
    int cond;
    
    if(p == NULL) {
        p = allocatenode();
        p->word = dupstring(w);
        p->cpt = 1;
        p->left = p->right = NULL;
    } else if((cond = strcmp(w, p->word)) == 0) p->cpt++;
    else if(cond < 0) p->left = addtree(p->left, w);
    else p->right = addtree(p->right, w);

    return p;
}

int createList(struct node *p) {
    static int n;
    if(p != NULL) {
        createList(p->left);
        list[n++] = p;
        createList(p->right);
    }
    return n;
}

void sortlist(int left, int right) {
    int i, last;

    if(left >= right) return;

    exchange(left, (left + right)/2);
    last = left;
    for(i = left+1; i <= right; i++) {
        if(list[i]->cpt > list[left]->cpt) exchange(++last, i);
    }

    exchange(left, last);
    sortlist(left, last-1);
    sortlist(last+1, right);
}

void exchange(int i, int j) {
    void *temp;

    temp = list[i];
    list[i] = list[j];
    list[j] = temp;
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
