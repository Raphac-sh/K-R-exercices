#include <stdio.h>
#include <ctype.h>

#define MAX 100
#define INCTAB 8

void tabulate(char *tab);
void detabulate(char *tab); 
void putTab(int argc, char *argv[], char *tab);
int atoi(char *s); 

int main(int argc, char *argv[]) {
    char  tab[MAX];
    putTab(argc, argv, tab);

    tabulate(tab);
    return 0;
} 

void tabulate(char *tab) {
    char c;
    int tabs, spaces = 0;
    
    for(int i = 0; (c = getchar()) != EOF && i < MAX; i++) {
        if(c == ' ') {
            if(tab[i]) {
                spaces = 0;
                tabs++;
            } else spaces++;
        } else {
            if(tabs > 0)
                while(--tabs >= 0) putchar('\t'); 
            else {
                if(spaces > 0)
                    while(--spaces >= 0) putchar(' ');
            }
            
            putchar(c);
            if(c == '\n') i = 0;
            else if(c == '\t') {
                while(!tab[i++]);
            }
        }
    }
}

void detabulate(char *tab) {
    char c;
    int i = 0;
    
    while((c = getchar()) != EOF)  {

        if(c == '\t') {
            do {
                putchar(' ');
            } while(!tab[i++]);
        } else {
            putchar(c);
            ++i;
        }
    }

}

void putTab(int argc, char *argv[], char *tab) {
    if(argc <= 1) {
        for(int i = 0; i < MAX; i++) {
            if(!(i % INCTAB)) tab[i] = 1;
            else tab[i] = 0; 
        }
    } else if(argc == 3 && *argv[1] == '-' && *argv[2] == '+') {
        int inc = atoi((++argv[2]));
        int tabs = atoi((++argv[1]));

        for(int i = 0; i <= MAX; i++) {
            if(i == tabs) {
                tab[i] = 1;
                tabs += inc;
            } else tab[i] = 0; 

    } else 
        for(int i = 0; i < MAX; i++) tab[i] = 0; 

        argc--;
        argv++;
        while(argc--) {
            if (atoi(*argv) >= 0 && atoi(*argv) < MAX)
                tab[atoi(*argv++)] = 1;
        }
    }
}

int atoi(char *s) {
    int val = 0;
    int sign;

    while(isspace(*s)) s++;

    sign = (*s == '-') ? -1 : 1;

    if(*s == '-' || *s == '+') s++;
    while(isdigit(*s)) {
        val = 10 * val + (*s - '0');
        s++;
    }
    val = val * sign;

    return val;
}
