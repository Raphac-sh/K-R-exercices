#include <stdio.h>

int puiss(int a, int b);
int setBits(int x, int y, int p, int n);

int main(void) {
	int x, y, p, n;
	x = 77;
	y = 20;
	p = 3;
	n = 2;
	
	printf("%d", setBits(x, y, p, n));

	return 0;
}

int setBits(int x, int y, int p, int n) {
	int result;

	result = ((y & (puiss(2, n) - 1)) << (p + 1 - n)) |
		((~((puiss(2, n) - 1) << (p + 1 - n))) & x);

	return result;
}

int puiss(int a, int b) {
	if(b == 0) return 1;
	int result = a;
	for(int i = 1; i < b; i++) {
		result = result * a;
	}
	return result;
}

