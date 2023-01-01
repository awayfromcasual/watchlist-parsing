
#include <stdio.h>

#define BUF_SIZE 200

int main()
{
    printf("Hello, Fen!\n");

    char input[BUF_SIZE];

    fgets(input, BUF_SIZE, stdin);

    char start_date[13], end_date[13], title[100], score[4];

    sscanf(input, "%s %s %[^\t] %s", start_date, end_date, title,
           score);

    printf("%s\n", start_date);
    printf("%s\n", end_date);
    printf("%s\n", title);
    printf("%s\n", score);

    return 0;
}
