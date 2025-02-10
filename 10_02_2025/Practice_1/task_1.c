#include <stdio.h>

int main()
{
    int mass;
    printf("Enter mass: ");
    scanf("%d", &mass);

    if (mass < 60 || mass > 90) 
    {
        puts("No, you can't.");
    }
    
    else
    {
        puts("Yes, you can.");
    }
}