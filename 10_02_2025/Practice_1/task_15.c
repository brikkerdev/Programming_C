#include <stdio.h>
#include <math.h>

int main()
{
    int speed;
    int data;

    printf("Enter speed (Kb/s): ");
    scanf("%d", &speed);
    printf("Enter data (Mb): ");
    scanf("%d", &data);
    
    float time = data * 8000. / speed / 60.;

    printf("Time to transfer (minutes): %.2f\n", time);
}