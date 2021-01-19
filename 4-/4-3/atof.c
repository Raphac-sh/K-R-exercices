#include <stdio.h>
#include <ctype.h>
#include "calc.h"

double atof(char s[]);

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
