#include <stdio.h>
#include <math.h>

int main()
{
    int astronauts;

    printf("Print number of astronauts: ");
    scanf("%d", &astronauts);

    int modules = 0;
    int variant = 0;
    int buffer = astronauts;

    do
    {
        if (astronauts % 4 == 0)
        {
            variant = 4;
            modules = astronauts / 4;
        }
        else if (astronauts % 3 == 0)
        {
            variant = 3;
            modules = astronauts / 3;
        }
        else if (astronauts % 2 == 0)
        {
            variant = 2;
            modules = astronauts / 2;
        }
        astronauts -= 1;
    } while (astronauts % 2 == 0);

    printf("%d-people teams: ", variant);
    printf("%d\n", modules);
    
    if (buffer % 2 != 0)
    {
        puts("One astronaut without team.");
    }
}