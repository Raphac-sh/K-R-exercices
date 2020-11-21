#include <stdio.h>

int countBits(unsigned int x);

int main(void) {
	int x = 6738;

	printf("%d", countBits(x));	
}

int countBits(unsigned int x) {
	int bits;
	for(bits = 0; x != 0; x &= x - 1) bits++;

	return bits;	
}
