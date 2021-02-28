#include <stdio.h>
#include <ctype.h>

#define TAILLETAMP 100

char tamp[TAILLETAMP];
int ptamp = 0;

int read_int(int *pn);
int readcar(void);
void pushcar(int c); 

int main(void) {
    int n = 0;

    read_int(&n);

    printf("%d", n);

    return 0;
}

int read_int(int *pn) {
    int c, sign;

    while (isspace(c = readcar()));

    if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
        pushcar(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-') {
        int d = c;
        if(!isdigit(c = readcar())) {
            if(c != EOF) {
                pushcar(c);
            }
            pushcar(d);
            return 0;
        }
    }

    for(*pn = 0; isdigit(c); c = readcar()) {
        *pn = 10 * *pn + ((c - '0'));
    }
    *pn *= sign;

    if(c != EOF) {
        pushcar(c);
    }
    return c;
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
