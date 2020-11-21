#include <stdio.h> 

int dicho(int x, int v[], int n);

int main(void) {
	int x, n;
	int v[] = {1, 5, 8, 9, 13};

	x = 8;
	n = 5;

	printf("%d", dicho(x, v, n));
}

int dicho(int x, int v[], int n) {
	int haut, bas, milieu;

	haut = n - 1;
	bas = 0;

	while(bas <= haut || x != v[milieu]) {
		milieu = (haut+bas) / 2;

		if(x < v[milieu]) {
			haut = milieu - 1;
		}
		else {
			bas = milieu + 1;
		} 
	}

	if(x == v[milieu]) {
		return milieu;
	}
	else {
		return -1;
	}
}
