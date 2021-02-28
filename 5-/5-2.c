#include <stdio.h>
#include <ctype.h>

#define TAILLETAMP 100

char tamp[TAILLETAMP];
int ptamp = 0;

int read_float(float *pn);
int readcar(void);
void pushcar(int c); 

int main(void) {
    float n = 0;

    read_float(&n);

    printf("%f", n);

    return 0;
}

int read_float(float *pn) {
    int c, sign, puiss;

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

    for(*pn = 0; isdigit(c); (c = readcar())) {
        *pn = 10 * *pn + ((c - '0'));
    }

    if(c == '.') c = readcar();

    for(puiss = 1.0; isdigit(c); c  = readcar()) {
		*pn = 10.0 * *pn + (c - '0');
        puiss *= 10.0;
	}

    *pn = *pn * sign / puiss;
    
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
