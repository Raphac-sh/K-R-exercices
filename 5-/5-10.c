#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NOMBRE 0
#define NOM 'n'

double atof(char s[]);
int lire_op(char arg[]);

int main(int argc, char *argv[]) {
    double stack[100];
    int i = 0;

    if(argc <= 3) {
        printf("Erreur, usage : expr 'valeur1' 'valeur2' 'opérateur'");
    } else {
        double result;
        while(argc--) {
            switch(lire_op(*argv)) {
                case NOMBRE:
                    stack[i++] = atof(*argv);
                    break;

                case '+':
                    if(stack[i-1] && stack[i-2]) {
                        result = stack[i-1] + stack[i-2];
                        stack[i-2] = result;
                        i -= 1;
                    }
                    break;
                        
                case '-':
                    if(stack[i-1] && stack[i-2]) {
                        result = stack[i-2] - stack[i-1];
                        stack[i-2] = result;
                        i -= 1;
                    }
                    break;

                case '*':
                    if(stack[i-1] && stack[i-2]) {
                        result = stack[i-1] * stack[i-2];
                        stack[i-2] = result;
                        i -= 1;
                    }
                    break;
                
                case '/':
                    if(stack[i-1] && stack[i-2]) {
                        result = stack[i-1] / stack[i-2];
                        stack[i-2] = result;
                        i -= 1;
                    }
                    break;

            }
            argv++;
        }
        printf("result : %f", result);
    }

    return 0;
}

double atof(char s[]) {
	double val, puiss;
	int i, sign;

	for(i = 0; isspace(s[i]); i++);

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-') i++;
	for(val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}

	if(s[i] == '.') i++;
	for(puiss = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		puiss *= 10.0;
	}
	val = sign * val / puiss;

	if(s[i++] == 'e') {
		sign = (s[i++] == '-') ? -1 : 1;

		int exp;
		for(exp = 0; isdigit(s[i]); i++) {
			exp = 10 * exp + (s[i] - '0');
		}

		if(sign > 0) {
			while(exp-- > 0) {
				val *= 10.0;
			}			
		} else if(sign < 0) {
			while(exp-- > 0) {
				val /= 10.0;
			}
		}
	}

	return val;
}

int lire_op(char arg[]) {
    int i = 0;
    int c;

	while((c = arg[i++]) == ' ' || c == '\t');

	if(islower(c)) {
		while (islower(c = arg[++i]));

		if(c != EOF) i--;
		if(strlen(arg) > 1) return NOM;
		else return c;
	}

	if(!isdigit(c) && c != '.' && c != '-') return c;

	if(c == '-') {
		if(isdigit(c = arg[i++]) || c == '.');
		else {
			if(c != EOF) i--;
			return '-';
		}
	}

	if(isdigit(c)) {
		while (isdigit(c = arg[i++]));
	}

	if(c == '.') {
		while((c = arg[i++]));
	}

	if(c == 'e') {
		while ((isdigit(c = arg[i++])));
	}


    if(c != EOF) {
        i--;
    }

	return NOMBRE;
}
