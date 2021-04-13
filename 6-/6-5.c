#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENHASH 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

unsigned hash(char *s);
char *dupstring(char *s);
struct nlist *put(char *name, char *defn);
struct nlist *search(char *s);

static struct nlist *arrhash[LENHASH];

int main(void) {

    return 0;
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
