#include <stdio.h>
#include <math.h>

int main()
{
    int temp;

    printf("Print temp: ");
    scanf("%d", &temp);
    
    if (temp >= -150 && temp <= 120)
    {
        puts("Can be.");
    }
    else
    {
        puts("Can't be");
    }
}