#include <stdio.h>
#include <limits.h>
#include <float.h>

long long int power(int num,  int exp);

int main(void)
{
    printf("Using header file :\n\n");
    
    printf("    SIGNED :\n\n");
    printf("CHAR; max: %d, min: %d\n", CHAR_MAX, CHAR_MIN);
    printf("SHORT; max: %d, min: %d\n", SHRT_MAX, SHRT_MIN);
    printf("INT; max: %d, min: %d\n", INT_MAX, INT_MIN);
    printf("LONG; max: %ld, min: %ld\n", LONG_MAX, LONG_MIN);
    
    printf("\n\n    UNSIGNED :\n\n");
    printf("CHAR; max: %d\n", UCHAR_MAX);
    printf("SHORT; max: %d\n", USHRT_MAX);
    printf("INT; max: %u\n", UINT_MAX);
    printf("LONG; max: %lu\n", ULONG_MAX);
	
	printf("\n Floating numbers :\n");
	printf("FLOAT; max: 10^%d, min: 10^%d\n", FLT_MAX_10_EXP, FLT_MIN_10_EXP);
    printf("DOUBLE; max: 10^%d, min: 10^%d\n", DBL_MAX_10_EXP, DBL_MIN_10_EXP);

    printf("\n\n\n");

    long long i = power(2, 32);
    unsigned long l = power(2, 64);
    long long c = power(2, 8);
    long long s = power(2, 16);

    printf("Using calculations :\n\n");

    printf("    SIGNED :\n\n");
    printf("CHAR; max: %lld, min: %lld\n", c-1, c-(2*c));
    printf("SHORT; max: %lld, min: %lld\n", s-1, s-(2*s));
    printf("INT; max: %lld, min: %lld\n", i-1, i-(2*i));
    printf("LONG; max: %lld, min: %lld\n", (long long) l-1, (long long) l - (2*l));

    printf("\n\n    UNSIGNED :\n\n");
    printf("CHAR; max: %lld\n", c*2-1);
    printf("SHORT; max: %lld\n", s*2-1);
    printf("INT; max: %lld\n", i*2-1);
    printf("LONG; max: %lu\n", l*2-1);
    return 0;
}

long long power( int num, int exp) {
     long long res = num;

     for (int i = num; i < exp; i++) {
         res = res * num;
     }

    return res;
}
