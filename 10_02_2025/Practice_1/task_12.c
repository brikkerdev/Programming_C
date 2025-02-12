#include <stdio.h>
#include <math.h>

int main()
{
    int angle;

    printf("Print angle: ");
    scanf("%d", &angle);
    
    if (angle % 360 >= -180 && angle % 360 <= 180)
    {
        puts("In range.");
    }
    else
    {
        puts("Not in range.");
    }
}