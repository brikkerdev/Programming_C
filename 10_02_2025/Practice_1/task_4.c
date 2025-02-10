#include <stdio.h>

int main()
{
    int start_date = 20250210;
    int date;

    scanf("%d", &date);

    if (date > start_date)
    {
        puts("In future");
    }
    else
    {
        puts("Not in future");
    }
}