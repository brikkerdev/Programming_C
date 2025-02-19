#include <stdio.h>
#include <stdbool.h>
#include "ship.h"

int main() {
    float speed, time;
    printf("Enter speed and time: ");
    scanf("%f %f", &speed, &time);
    printf("Calculated distance: %f\n", calculate_distance(speed, time));
    float fuel_level;
    float max_fuel = 1000;
    printf("Enter fuel level: ");
    scanf("%f", &fuel_level);
    printf("Fuel status: %s\n", check_fuel(fuel_level, max_fuel) == true ? "Normal" : "Caution");
    return 0;
}