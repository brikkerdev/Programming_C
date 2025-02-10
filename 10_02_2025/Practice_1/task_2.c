#include <stdio.h>

int main()
{
    int dist;
    printf("Enter dist: ");
    scanf("%d", &dist);

    if (dist > 500) 
    {
        puts("No, you can't.");
    }
    
    else
    {
        puts("Yes, you can.");
    }
}