#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int pp = 0;

double val[MAXVAL];

void empiler(double f) {
	if(pp < MAXVAL) {
		val[pp++] = f;
	} else {
		printf("pile pleine, impossible d'empiler %g\n", f);
	}
}

double depiler(void) {
	if (pp > 0) {
		return val[--pp];
	} else {
		printf("erreur : pile vide\n");
		return 0.0;
	}
}

void vide() {
	pp = 0;
}
