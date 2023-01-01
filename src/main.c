
#include <stdio.h>

#define BUF_SIZE 120

int main()
{
    printf("Hello, Fen!\n");

    char input[BUF_SIZE];

    fgets(input, BUF_SIZE, stdin);

    char start_date[13], end_date[13], title[90];

    sscanf(input, "%s %s %[^\n]", start_date, end_date, title);

    printf("%s\n", start_date);
    printf("%s\n", end_date);
    printf("%s\n", title);

    return 0;
}
