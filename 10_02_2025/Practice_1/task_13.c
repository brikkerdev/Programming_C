#include <stdio.h>
#include <math.h>

int main()
{
    int n;

    printf("Enter number of cosmonauts: ");
    scanf("%d", &n);
    
    if (n % 2 == 0)
    {
        puts("Yes, you can.");
    }
    else
    {
        puts("No, you can't.");
    }
}