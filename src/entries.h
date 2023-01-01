
#pragma once

#include "dates.h"

#define MAX_TITLE_LENGTH 100

typedef struct entry
{
    date_t start_date;
    date_t end_date;
    char title[MAX_TITLE_LENGTH];
    int score;
} entry_t;

void entry_to_string(entry_t e, char* dest);

void string_to_entry(char* src);

void print_entry(entry_t e);

void sort_entries(entry_t* entries, int num_entries, int asc);
