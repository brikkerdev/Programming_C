#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    Gasoline,
    Diesel,
    Electric
} EngineType;

typedef struct {
    char name[50];
    char model[50];
    int year;
    EngineType engine_type;
} Vehicle;

int main()
{
    int n;
    scanf("%d", &n);
    Vehicle* vehicles = malloc(sizeof(Vehicle) * n);

    for (int i = 0; i < n; i++)
    {
        char engine_type[9];

        scanf(
            "%s %s %d %s", 
            vehicles[i].name,
            vehicles[i].model,
            &vehicles[i].year,
            engine_type
        );

        if (!strcmp(engine_type, "Gasoline")) {
            vehicles[i].engine_type = Gasoline;
        }
        else if(!strcmp(engine_type, "Diesel")) {
            vehicles[i].engine_type = Diesel;
        }
        else if(!strcmp(engine_type, "Electric")) {
            vehicles[i].engine_type = Electric;
        }
        else {
            puts("Wrong engine type input (Gasoline, Diesel, Electric)");
            printf("You typed: %s\n", engine_type);
            return 1;
        }
    }

    for (int i = 0; i < n; i++)
    {

        printf(
            "Vehicle: %s %s\nYear: %d\nEngine Type: %s\n\n", 
            vehicles[i].name, 
            vehicles[i].model, 
            vehicles[i].year, 
            vehicles[i].engine_type == 0 ? "Gasoline" :
            vehicles[i].engine_type == 1 ? "Diesel" : "Electric"
        );
    }

    free(vehicles);
    return 0;
}