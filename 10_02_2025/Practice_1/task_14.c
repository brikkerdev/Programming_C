#include <stdio.h>
#include <math.h>

int main()
{
    int mass;

    printf("Enter mass: ");
    scanf("%d", &mass);
    
    float weight = mass * 10 / 6.;

    printf("Weight on Moon: %f\n", weight);
}