#include <stdio.h>

int puiss(int a, int b);
int rotateBits(int x, int n);

int main(void) {
	int x, n;
	x = 77;
	n = 2;
	
	printf("%d", rotateBits(x, n));

	return 0;
}

int rotateBits(int x, int n) {
	int result;
	int length(void);

	result = (x >> n) |(((puiss(2, n) - 1) & x) << (length() - n));

	return result;
}

int length(void) {
	unsigned int num = (unsigned) ~0;
	int i;

	for(i = 1; (num = num >> 1) > 0; i++);

	return i;
}

int puiss(int a, int b) {
	if(b == 0) return 1;
	int result = a;
	for(int i = 1; i < b; i++) {
		result = result * a;
	}
	return result;
}

