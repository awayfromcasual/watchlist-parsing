
#pragma once

#include "dates.h"

// Characters allowed in a title
#define TITLE_SIZE 100

// Struct for storing entries
typedef struct entry
{
    date_t start_date;
    date_t end_date;
    char title[TITLE_SIZE];
    int score;
} entry_t;

// Allowable sort orders
typedef enum orders
{
    START_DATE = 0,
    END_DATE,
    TITLE,
    SCORE
} order_t;

// Convert entry to string and store it in dest
void entry_to_string(entry_t e, char* dest);

// Convert string to entry
entry_t string_to_entry(char* src);

// Print an entry
//  - Param allows for ascending or descending sort order.
void print_entry(entry_t e, char c);

// Sort an array of type entry_t[]
//  - Param allows for ascending or descending sort order.
void sort_entries(entry_t* entries, int num_entries, order_t ord,
                  int reverse);
