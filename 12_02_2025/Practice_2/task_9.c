#include <stdio.h>
#include <string.h>

typedef enum {
    Sunny,
    Cloudy,
    Rainy
} WeatherType;

typedef struct {
    float temp;
    float humidity;
    WeatherType weather_type;
} Weather;

int main()
{
    Weather weather;

    char weather_type[7];

    scanf(
        "%f %f %6s", // теперь мы знаем, что лучше ограничивать число символов при вводе -)
        &weather.temp,
        &weather.humidity,
        weather_type
    );
    
    if (weather.humidity < 0 || weather.humidity > 100) {
        puts("Wrong humidity (0-100%)");
        printf("You typed %.1f\n", weather.humidity);
        return 1;
    }

    if (!strcmp(weather_type, "Sunny")) {
        weather.weather_type = Sunny;
    }
    else if(!strcmp(weather_type, "Cloudy")) {
        weather.weather_type = Cloudy;
    }
    else if(!strcmp(weather_type, "Rainy")) {
        weather.weather_type = Rainy;
    }
    else {
        puts("Wrong weather type input (Sunny, Cloudy, Rainy)");
        printf("You typed: %s\n", weather_type);
        return 1;
    }

    printf(
        "Temperature: %.1f°C\nHumidity: %.1f%%\nCondition: %s\n\n", 
        weather.temp, 
        weather.humidity, 
        weather.weather_type == 0 ? "Sunny" :
        weather.weather_type == 1 ? "Cloudy" : "Rainy"
    );

    return 0;
}
