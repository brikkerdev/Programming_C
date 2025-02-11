#include <stdio.h>
#include <math.h>

int main()
{
    double calculated_speed;
    double actual_speed;
    double difference;

    printf("Print calculated speed: ");
    scanf("%lf", &calculated_speed);
    printf("Print actual speed: ");
    scanf("%lf", &actual_speed);

    difference = fabs(calculated_speed - actual_speed);

    if (difference > 0.1f)
    {
        printf("Difference: %lf\n", difference);
        puts("Unstable orbit");
    }
    else
    {
        printf("Difference: %lf\n", difference);
        puts("Stable orbit");
    }
}