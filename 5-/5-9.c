#include <stdio.h>

int day_year(int year, int month, int day); 
void month_day(int year, int dayYear, int *pmois, int *pjour);

static char tabday[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void) {
    int dayOfYear;
    dayOfYear = day_year(2020, 2, 19);
    printf("%d; ", dayOfYear);

    int month = 0;
    int day = 0;
    month_day(2020, dayOfYear, &month, &day); 
    printf("%d, %d", month, day);
    
    return 0;
}

int day_year(int year, int month, int day) {
    int bis;

    if(year < 0) return -1;
    if(month < 1 || month > 12) return -1;
    if(day < 1 || day > 31) return -1;

    bis = year%4 == 0 && year%100 != 0 || year%400 == 0;

    char *p = tabday[bis];
    while(month--) day += *p++;

    return day;
}

void month_day(int year, int dayYear, int *pmois, int *pjour) {
    int i, bis;

    if(year < 0) return;
    if(dayYear < 1 || dayYear > 365) return;

    bis = year%4 == 0 && year%100 != 0 || year%400 == 0;

    char *p = tabday[bis];
    while(dayYear > *p) dayYear -= *p++;

    *pmois = i;
    *pjour = dayYear;
}
