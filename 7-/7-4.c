#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void minscanf(char *fmt, ...);

int main(void) {
    char var[100];
    minscanf("%s", &var);
    printf("%s", var);

    return 0;
}

void minscanf(char *fmt, ...) {
    va_list pa;

    char *p, *vals;
    int *vali;
    double *vald;
    unsigned int *valu;

    va_start(pa, fmt);

    for(p = fmt; *p; p++) {
        char *s = malloc(100);
        char *format = s;
        if(*p != '%') {
            putchar(*p);
            continue;
        } else {
            *s++ = *p++;
            *s++ = *p;
        }

        switch(*p) {
            case 'd':
            case 'i':
            case 'c':
            case 'o':
            case 'x':
                vali = va_arg(pa, int *);
                scanf(format, vali);
                break;

            case 'f':
            case 'e':
            case 'g':
                vald = va_arg(pa, double *);
                scanf(format, vald);
                break;

            case 'u':
                valu = va_arg(pa, unsigned int *);
                scanf(format, valu);
                break;

            case 's':
                vals = va_arg(pa, char *); 
                scanf(format, vals);
                break;

            default:
                putchar(*p);
                break;
        }
    }

    va_end(pa);
}
