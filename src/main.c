
#include "dates.h"
#include "entries.h"

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 200

int main(int argc, char** argv)
{
    printf("Hi, Fen!\n");

    /*
     */

    // Get input file as command line parameter
    FILE* file_ptr;

    // Start at the top of the file
    file_ptr = fopen(argv[1], "r");

    // Input buffer
    char input[BUFFER_SIZE];

    while (fgets(input, BUFFER_SIZE, file_ptr) != NULL
           && *input != '\n')
    {
        // Parse input
        char start_date[13], end_date[13], title[100], score[4];
        sscanf(input, "%s %s %[^\t] %s", start_date, end_date,
               title, score);

        // Print what was read
        printf("%s\t%s\t%s\t%s\n", start_date, end_date, title,
               score);
    }

    printf("\n--------\n");

    /*
     */

    // Take input from file
    file_ptr = fopen(argv[1], "r");
    fgets(input, BUFFER_SIZE, file_ptr);

    // Convert input to entry
    entry_t entry = string_to_entry(input);
    print_entry(entry, '\n');

    /*
     */

    printf("Bye, Fen.");

    return 0;
}
