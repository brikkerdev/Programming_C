#include <stdio.h>
#include <math.h>

int main()
{
    float oxygen;

    printf("Print oxygen percentage: ");
    scanf("%f", &oxygen);
    
    if (oxygen >= 0 && oxygen < 15)
    {
        puts("Alarm!");
    }
    else if (oxygen < 0 || oxygen > 100)
    {
        puts("Invalid value.");
    }
    else
    {
        puts("Okay.");
    }
}