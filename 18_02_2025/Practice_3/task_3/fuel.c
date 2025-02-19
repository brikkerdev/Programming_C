#include <stdbool.h>

bool check_fuel(float fuel_level, float fuel_max) {
    return (fuel_level / fuel_max) > 0.1f;
}