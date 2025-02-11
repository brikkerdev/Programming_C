#include <stdio.h>
#include <math.h>

int main()
{
    int mass;

    printf("Print mass: ");
    scanf("%d", &mass);
    
    if (mass % 4 != 0)
    {
        puts("Can't separate this mass.");
    }
    else
    {
        printf("Mass of the part: %d\n", mass / 4);
    }

}