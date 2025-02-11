#include <stdio.h>
#include <math.h>

int main()
{
    double time;

    printf("Print time: ");
    scanf("%lf", &time);
    
    int minutes = time / 60;
    double seconds = time - (minutes * 60);

    printf("%d minutes ", minutes);
    printf("%lf seconds\n", seconds);
}