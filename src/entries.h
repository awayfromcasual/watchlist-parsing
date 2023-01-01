
#pragma once

#include "dates.h"

#define TITLE_SIZE 100

typedef struct entry
{
    date_t start_date;
    date_t end_date;
    char title[TITLE_SIZE];
    int score;
} entry_t;

void entry_to_string(entry_t e, char* dest);

entry_t string_to_entry(char* src);

void print_entry(entry_t e, char c);

void sort_entries(entry_t* entries, int num_entries, int asc);
