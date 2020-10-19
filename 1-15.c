#include <stdio.h>

float convert(float temp);

int main(void)
{
    float fahr, celc;
    int min, max, interval;

    fahr = celc = min = 0;
    max = 300;
    interval = 20;

    while(fahr <= max) {
        celc = convert(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celc);
        fahr += interval;
    }

    return 0;
}

float convert(float temp) {
    return (5.0/9.0) * (temp - 32);
}