#include <stdio.h>
#include <math.h>
#include <string.h>
#include "calc.h"
#define MAXOP 100

void commands(char s[]);

/*calculatrice en polonaise inversée*/
int main(void) {
	int type, v;
	double op1, op2;
	char s[MAXOP];
	double var[26];
	double l;

	while((type = lire_op(s)) != EOF) {
		switch(type) {
			case NOMBRE:
				empiler(atof(s));
				break;
			case NOM:
				commands(s);
				break;
			case '+':
				empiler(depiler() + depiler());
				break;
			case '*':
				empiler(depiler() * depiler());
				break;
			case '-':
				op2 = depiler();
				empiler(depiler() - op2);
				break;
			case '/':
				op2 = depiler();
				if(op2 != 0.0) {
					empiler(depiler() / op2);
				} else {
					printf("erreur : division par zéro\n");
				}
				break;
			case '%':
				op2 = depiler();
				if(op2 != 0.0) {
					empiler(fmod(depiler(), op2));
				} else {
					printf("erreur : division par zéro\n");
				}
				break;
			case '=':
                depiler();
				if(v >= 'A' && v <= 'Z') {
                    var[v - 'A'] = depiler();
                    empiler(var[v - 'A']);
                }
				else printf("erreur: pas de variable %d \n", v - 'A');
				break;
			case '\n':
				l = depiler();
				printf("\t%.8g\n", l);
				break;
			default:
				if(type >= 'A' && type <= 'Z') empiler(var[type - 'A']);
				else if(type == 'l') empiler(l);
				else printf("erreur: commande inconnue %s\n", s);
				break;
		}
		v = type;
	}

	return 0;
}

void commands(char s[]) {
	double op2;

	if(strcmp(s, "sin") == 0) {
		empiler(sin(depiler()));
	} else if(strcmp(s, "cos") == 0) {
		empiler(cos(depiler()));
	} else if(strcmp(s, "exp") == 0) {
		empiler(exp(depiler()));
	} else if(strcmp(s, "pow") == 0) {
		op2 = depiler();
		empiler(pow(depiler(), op2));
	} else printf("erreur : %s n'est pas une opération ou fonction\n", s);
}
