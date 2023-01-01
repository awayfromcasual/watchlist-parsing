
#include "entries.h"
#include "dates.h"

#include <stdio.h>
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

void sort_entries(entry_t* entries, int num_entries, int asc)
{
    ;
}
