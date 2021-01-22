#include <stdio.h>
#include <string.h>

int reverse_char(char s[], int i, int len); 
int reverse(char s[]);

int main(void) {
    char s[] = "Hello, world!";

    reverse(s);

    printf("%s", s);

    return 0;
}

int reverse(char s[]) {
    reverse_char(s, 0, strlen(s));
}

int reverse_char(char s[], int i, int len) {
    char c;
    
    if(i < len) {
        c = s[i];
        s[i] = s[len-1];
        s[len-1] = c;
    
        reverse_char(s, i+1, len-1);
    }
}
