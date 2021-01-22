#include <stdio.h>
#define MAX 100
 
void itos(int n, char s[]);

int main(void) {
    int n = 654;
    char s[MAX];

    itos(n, s);

    printf("%s", s);

    return 0;
}

void itos(int n, char s[]) {
    static int i = 0;

    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10) itos(n / 10, s);
    s[i++] = n % 10 + '0';
}
