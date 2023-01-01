
#pragma once

// Date formats
#define INPUT_FORMAT DD_MMM_YYYY

// For sorting dates
#define REVERSE 1

// The name of each month
extern const char* month_names[13];

// Struct for storing dates
typedef struct date
{
    int month;
    int day;
    int year;
} date_t;

// Allowable date formats
typedef enum formats
{
    MMM_DD_YYYY = 0,
    DD_MMM_YYYY
} format_t;

// Convert date to string and store it in dest
//  - String will be of the form (Jul 02, 2022)
void date_to_string(date_t date, char* dest);

// Convert string to date
//  - String must be in the form specified by INPUT_FORMAT.
date_t string_to_date(char* src);

// Print a date
//  - Param allows a \t or a \n character to be inserted.
void print_date(date_t date, char c);

// Compare dates
//  - Returns (< 0) if p goes before q
//  - Returns (= 0) if p and q are equivalent
//  - Returns (> 0) if p goes after q
int compare_dates(const void* p, const void* q);

// Sort an array of type date_t[]
//  - Param gives option to reverse sort order.
void sort_dates(date_t* dates, int num_dates, int reverse);
