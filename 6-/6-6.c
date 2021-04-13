#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LENHASH 101
#define MAXWORD 100
#define TAILLETAMP 100

char tamp[TAILLETAMP];
int ptamp = 0;

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

unsigned hash(char *s);
char *dupstring(char *s);
struct nlist *put(char *name, char *defn);
struct nlist *search(char *s);
int readword(char *word, int lim);
int readcar(void);
void pushcar(int c);

static struct nlist *arrhash[LENHASH];

int main(void) {
    char *prev = "";
    char word[MAXWORD];

    int isdef = 0;
    struct nlist *pn;

    while(readword(word, MAXWORD) != EOF) {
        if(strcmp(word, "#define") == 0) isdef = 1; 
        else if(strcmp(prev, "#define") != 0 && isdef == 1) {
            if(put(prev, word) == NULL)
                printf("error : could not put definition");

            isdef = 0;
        }
        
        if((pn = search(word)) != NULL) {
            printf("%s", pn->defn);
        } else printf("%s", word);

        printf(" ");
        prev = dupstring(word);
    }
 

    return 0;
}

int readword(char *word, int lim) {
    int c, readcar(void);
    void pushcar(int);
    char *w = word;
    while(isspace(c = readcar()));

    if(c != EOF) *w++ = c;
    if(!isalpha(c) && c != '#') {
        *w = '\0';
        return c;
    }

    for( ; --lim > 0; w++) {
        if(!isalnum(*w = readcar()) && *w != '#') {
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

unsigned hash(char *s) {
    unsigned valhash;

    for(valhash = 0; *s != '\0'; s++)
        valhash = *s + 31 * valhash;

    return valhash % LENHASH;
}

struct nlist *search(char *s) {
    struct nlist *pn;

    for(pn = arrhash[hash(s)]; pn !=NULL; pn = pn->next)
        if(strcmp(s, pn->name) == 0)
            return pn;

    return NULL;
}

struct nlist *put(char *name, char *defn) {
    struct nlist *pn;
    unsigned valhash;

    if((pn = search(name)) == NULL) {
        pn = (struct nlist *) malloc(sizeof(*pn));

        if(pn == NULL || (pn->name = dupstring(name)) == NULL)
            return NULL;

        valhash = hash(name);
        pn->next = arrhash[valhash];
        arrhash[valhash] = pn;
    } else free((void *) pn->defn);

    if((pn->defn = dupstring(defn)) == NULL) return NULL;

    return pn;
}

void deleteDef(char *name) {
    struct nlist *pn, *previous;

    previous = NULL;
    int h = hash(name);
    for(pn = arrhash[h]; pn !=NULL; pn = pn->next) {
        if(strcmp(name, pn->name) == 0) break;
        previous = pn;
    }
    if(pn != NULL) {
        if(previous == NULL) arrhash[h] = pn->next;
        else previous->next = pn->next;

        free(pn->name);
        free(pn->defn);
        free(pn);
    }

}

char *dupstring(char *s) {
    char *p;

    p = (char *) malloc(strlen(s)+1);
    if(p != NULL) strcpy(p, s);
    return p;
}
