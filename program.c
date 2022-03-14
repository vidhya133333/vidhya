#include <stdio.h>

char *months[] =
    {
     " ",
     "\nJanuary", 
     "\nFebruary",
     "\nMarch",
     "\nApril",
     "\nMay",
     "\nJune",
     "\nJuly",
     "\nAugust",
      "\nSeptember",
     "\nOctober",
     "\nNovember",
     "\nDecember"
    };

int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31 ,31 ,30, 31, 30, 31};

int first_day_year(int year)
{
    int first_day;
    int x;
    int y;
    int z;

    x = (year - 1.)/4.0;
    y = (year - 1.)/100.;
    z = (year - 1.)/400.;

    first_day = (year + x - y + z) %7;

    return first_day;
}

int leapyear(int year)
{
    if(year%4 == 0 && year%100 != 0 || year%400 == 0)
    {
        month_days[2] = 29;
        return 1;
    } else {
        month_days[2] = 28;
        return 0;
    }
}

int calendar(int date,int month, int year, int first_day)
{
    int i;

    printf("%s %d\n\n", months[month], year);
    printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for(i = 0; i < month; i++)
    {
        first_day = (first_day + month_days[month]) % 7;
    }

    for(i = 1; i <= 1 + first_day * 5; i++)
    {
        printf(" ");
    }

    for(i = 1; i <= month_days[month]; i++)
    {
        printf("%2d", i);

        if((i + first_day)%7 > 0)
            printf("   ");
        else
            printf("\n ");
    }
}

int main(void)
{
    int year;
    int month;
    int date;
    int first_day;

    do{
        printf("Enter a month (1 - 12): ");
        scanf("%d", &month);
    } while (month < 1 || month > 12);

    do{
        printf("Enter a year (1978 - 3000): ");
        scanf("%d", &year);
    } while (year < 1978 || year > 3000);
    do{
        printf("Enter a date : ");
        scanf("%d", &date);
    } while (date < 1 || date > 31);

    first_day = first_day_year(year);
    leapyear(year);
    calendar(date,month, year, first_day);
    
    printf("\n");

    return 0; 
}

