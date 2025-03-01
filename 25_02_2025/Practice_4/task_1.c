#include <stdio.h>
#include <string.h>

#define MAX_SHIPS 100
#define MAX_LEN 50

int nameCheck(const char *name)
{
    return strncmp(name, "SS", 2) == 0;
}

int main()
{
    char ships[MAX_SHIPS][MAX_LEN] = 
    {
        "SShuttle", 
        "STurtle", 
        "SSSR", 
        "StarSearcher", 
        "SSearcher", 
        "SuperRocket", 
        "SSD", 
        "SSlim", 
        "Soyuz", 
        "SSoyus"
    };

    int ships_len = 10;
    int founded = 0;

    for (int i = 0; i < ships_len; i++)
    {
        if (nameCheck(ships[i]))
        {
            printf("Найден корабль: %s\n", ships[i]);
            founded ++;
        }
    }
    if (!founded) printf("Таких кораблей нет.\n");
    return 0;
}