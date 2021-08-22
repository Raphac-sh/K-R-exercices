#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

int main(void) {
    minprintf("lol %x", 18);

    return 0;
}

void minprintf(char *fmt, ...) {
    va_list pa;

    char *p, *vals;
    int vali;
    double vald;
    unsigned int valu;

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
                vali = va_arg(pa, int);
                printf(format, vali);
                break;

            case 'f':
            case 'e':
            case 'E':
            case 'g':
            case 'G':
                vald = va_arg(pa, double);
                printf(format, vald);
                break;

            case 'u':
            case 'o':
            case 'x':
            case 'X':
                valu = va_arg(pa, unsigned int);
                printf(format, valu);
                break;

            case 's':
                for(vals = va_arg(pa, char *); *vals; vals++)
                    putchar(*vals);
                break;

            default:
                putchar(*p);
                break;
        }
    }

    va_end(pa);
}
