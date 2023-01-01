
#include "entries.h"
#include "dates.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void entry_to_string(entry_t e, char* dest)
{
    char start_str[20], end_str[20];
    date_to_string(e.start_date, start_str);
    date_to_string(e.end_date, end_str);

    // Store formatted string
    sprintf(dest, "%s\t%s\t%s\t%d", start_str, end_str, e.title,
            e.score);
}

entry_t string_to_entry(char* src)
{
    // Parse input
    char start_str[20], end_str[20], title_str[100];
    int score;
    sscanf(src, "%s %s %[^\t] %d", start_str, end_str, title_str,
           &score);

    // Create dates from strings
    date_t start_date = string_to_date(start_str);
    date_t end_date = string_to_date(end_str);

    // Generate result
    entry_t res = (entry_t){start_date, end_date, "", score};
    strcpy(res.title, title_str);

    return res;
}

void print_entry(entry_t e, char c)
{
    char text[150];
    entry_to_string(e, text);
    printf("%s%c", text, c);
}

int compare_entries_by_start(const void* p, const void* q)
{
    entry_t e1 = *(const entry_t*) p;
    entry_t e2 = *(const entry_t*) q;

    return compare_dates(&(e1.start_date), &(e2.start_date));
}

int compare_entries_by_end(const void* p, const void* q)
{
    entry_t e1 = *(const entry_t*) p;
    entry_t e2 = *(const entry_t*) q;

    return compare_dates(&(e1.end_date), &(e2.end_date));
}

void sort_entries(entry_t* entries, int num_entries, order_t ord,
                  int reverse)
{
    if (ord == START_DATE)
        qsort(entries, num_entries, sizeof(entries[0]),
              compare_entries_by_start);
    else if (ord == END_DATE)
        qsort(entries, num_entries, sizeof(entries[0]),
              compare_entries_by_end);

    if (reverse)
    {
        int l = 0, r = num_entries - 1;
        while (l < r)
        {
            entry_t temp = entries[l];
            entries[l] = entries[r];
            entries[r] = temp;
            l++;
            r--;
        }
    }
}
