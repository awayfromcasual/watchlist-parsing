
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 200

int main(int argc, char** argv)
{
    printf("Hello, Fen!\n");

    // Get input file as command line parameter
    FILE* file_ptr;
    file_ptr = fopen(argv[1], "r");

    // Count lines in file
    int entries = 0;
    for (char c = getc(file_ptr); c != EOF; c = getc(file_ptr))
    {
        if (c == '\n')
            entries = entries + 1;
    }

    file_ptr = fopen(argv[1], "r");

    printf("Read %d entries\n", entries);

    for (int i = 0; i < entries; i++)
    {
        // Get input from command line
        char input[BUF_SIZE];
        fgets(input, BUF_SIZE, file_ptr);

        // Parse input
        char start_date[13], end_date[13], title[100], score[4];
        sscanf(input, "%s %s %[^\t] %s", start_date, end_date,
               title, score);

        // Print what was read
        printf("%s\t%s\t%s\t%s\n", start_date, end_date, title,
               score);
    }

    // Quit prompt
    char quit = 'a';
    while (quit != 'q')
    {
        printf("\nType 'q' to quit: ");
        scanf("%c", &quit);
    }

    return 0;
}
