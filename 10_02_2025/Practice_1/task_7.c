#include <stdio.h>
#include <math.h>

int main()
{
    float freq;

    printf("Print frequency: ");
    scanf("%f", &freq);
    
    if (freq >= 2.5 && freq <= 3.5)
    {
        puts("Frequency stable.");
    }
    else
    {
        puts("Frequency unstable.");
    }

}