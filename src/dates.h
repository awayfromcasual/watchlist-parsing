
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
//  - String will be of the form (Jul-02-2022)
void date_to_string(date_t date, char* dest);

// Convert string to date
//  - String must be in the form specified by INPUT_FORMAT.
date_t string_to_date(char* src);

// Print a date in the form (Jul-02-2022)
//  - Param allows a \t or a \n character to be inserted.
void print_date(date_t date, char c);

// Sort an array of type date_t[]
//  - Param allows for ascending or descending sort order.
void sort_dates(date_t* dates, int num_dates, int asc);
