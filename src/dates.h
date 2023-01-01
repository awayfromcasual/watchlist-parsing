
#pragma once

// Date formats
#define INPUT_FORMAT DD_MMM_YYYY

// For sorting dates
#define ASCENDING  true
#define DESCENDING false

// Struct for storing dates
typedef struct date
{
    int month;
    int day;
    int year;
} date_t;

typedef enum formats
{
    MMM_DD_YYYY = 0,
    DD_MMM_YYYY
} format_t;

// Convert date to string.
//  - String will be of the form (Jul-02-2022)
void date_to_string(date_t date, char* res);

// Convert date to string
//  -   String must be in the form specified by INPUT_FORMAT.
//  Options for the input format are in the format enum.
date_t string_to_date(char* s);

// Prints a date in the form (Jul-02-2022)
void print_date(date_t date, int newline);

// Takes in an array of type date_t[] and sorts it
void sort_dates(date_t* dates, int num_dates, int asc);
