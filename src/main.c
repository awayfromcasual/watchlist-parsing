
#include <stdio.h>

#define BUF_SIZE 150

int main()
{
    printf("Hello, Fen!\n");

    char input[200];

    fgets(input, BUF_SIZE, stdin);

    char start_date[20], end_date[20], title[100], score[10];
    int score;

    sscanf(input, "%s %s %[^\t] %d", start_date, end_date, title,
           score);

    printf("%s\n", start_date);
    printf("%s\n", end_date);
    printf("%s\n", title);
    printf("%d\n", score);

    return 0;
}
