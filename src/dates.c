
#include "dates.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void date_to_string(date_t date, char* dest)
{
    char* month_names[13] = {"err", "Jan", "Feb", "Mar", "Apr",
                             "May", "Jun", "Jul", "Aug", "Sep",
                             "Oct", "Nov", "Dec"};

    // Store formatted string
    if (date.month == 0)
        sprintf(dest, "err 00, 0000");
    else if (date.day < 10)
        sprintf(dest, "%s 0%d, %d", month_names[date.month],
                date.day, date.year);
    else
        sprintf(dest, "%s %d, %d", month_names[date.month],
                date.day, date.year);
}

date_t string_to_date(char* s)
{
    // Empty date
    if (*s == '-')
        return (date_t){0, 0, 0};

    char month_str[4];
    int month = 0, day = 0, year = 0;

    // Parse string
    if (INPUT_FORMAT == MMM_DD_YYYY)
        sscanf(s, "%[a-zA-Z]-%d-%d", month_str, &day, &year);
    else if (INPUT_FORMAT == DD_MMM_YYYY)
        sscanf(s, "%d-%[a-zA-Z]-%d", &day, month_str, &year);

    char* month_names[13] = {"err", "Jan", "Feb", "Mar", "Apr",
                             "May", "Jun", "Jul", "Aug", "Sep",
                             "Oct", "Nov", "Dec"};

    for (int i = 0; i < 13; i++)
    {
        if (strcmp(month_str, month_names[i]) == 0)
            month = i;
    }

    return (date_t){month, day, year};
}

void print_date(date_t date, char c)
{
    char text[20];
    date_to_string(date, text);
    printf("%s%c", text, c);
}

int date_comparator(const void* p, const void* q)
{
    date_t d1 = *(const date_t*) p;
    date_t d2 = *(const date_t*) q;

    if (d1.year == d2.year)
        return (d1.month == d2.month) ? (d1.day - d2.day)
                                      : (d1.month - d2.month);

    return d1.year - d2.year;
}

int date_reverse_comparator(const void* p, const void* q)
{
    date_t d1 = *(const date_t*) q;
    date_t d2 = *(const date_t*) p;

    if (d1.year == d2.year)
        return (d1.month == d2.month) ? (d1.day - d2.day)
                                      : (d1.month - d2.month);

    return d1.year - d2.year;
}

void sort_dates(date_t* dates, int num_dates, int asc)
{
    if (asc)
        qsort((void*) dates, num_dates, sizeof(dates[0]),
              date_comparator);
    else
        qsort((void*) dates, num_dates, sizeof(dates[0]),
              date_reverse_comparator);
}
