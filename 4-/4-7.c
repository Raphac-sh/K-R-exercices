#include <stdio.h>
#include <string.h>
#include <stdio.h>
#define TAILLETAMP 100

char tamp[TAILLETAMP];

int ptamp = 0;

void remettrech(char s[]);
int lirecar(void);
void remettrecar(int c);

int main(void) {
	char s[] = "bonjour";

	remettrech(s);	
			
	printf("%c", lirecar());
	printf("%c", lirecar());
	printf("%c", lirecar());
	printf("%c", lirecar());
	printf("%c", lirecar());
	printf("%c", lirecar());
	printf("%c", lirecar());
	
	return 0;
}

int lirecar(void) {
	return (ptamp > 0) ? tamp[--ptamp] : getchar();
}

void remettrecar(int c) {
	if(ptamp >= TAILLETAMP) {
		printf("remettrecar: trop de caractères");
	} else {
		tamp[ptamp++] = c;
	}
}

void remettrech(char s[]) {
	int pos = strlen(s);
	
	while(pos-- > 0) remettrecar(s[pos]);
}
