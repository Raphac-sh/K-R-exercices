#include <stdio.h>

int puiss(int a, int b);
int reverseBits(int x, int p, int n);

int main(void)
{
	int x, p, n;

	x = 10;
	p = 5;
	n = 2;

	printf("%d", reverseBits(x, p, n));	
    return 0;
}

int reverseBits(int x, int p, int n) {
	return (((puiss(2, n) - 1) << (p + 1 - n)) ^ x);
}

int puiss(int a, int b) {
	if(b == 0) return 1;
	int result = a;
	for(int i = 1; i < b; i++) {
		result = result * a;
	}
	return result;
}
