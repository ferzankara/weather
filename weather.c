#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITY_NAME_LENGTH 50

// Struct to hold weather data for each city
struct CityWeatherData {
    char city_name[MAX_CITY_NAME_LENGTH];
    float temperature;
    float wind_speed;
    float humidity;
};

// Function to find minimum and maximum values for the specified weather field
void findMinMax(struct CityWeatherData *city_weather_data_array, int num_cities, char *field, float *min_value, float *max_value, char *min_city_name, char *max_city_name) {
    *min_value = city_weather_data_array[0].temperature;
    *max_value = city_weather_data_array[0].temperature;
    strcpy(min_city_name, city_weather_data_array[0].city_name);
    strcpy(max_city_name, city_weather_data_array[0].city_name);

    if (strcmp(field, "wind") == 0) {
        for (int i = 0; i < num_cities; i++) {
            if (city_weather_data_array[i].wind_speed < *min_value) {
                *min_value = city_weather_data_array[i].wind_speed;
                strcpy(min_city_name, city_weather_data_array[i].city_name);
            }
            if (city_weather_data_array[i].wind_speed > *max_value) {
                *max_value = city_weather_data_array[i].wind_speed;
                strcpy(max_city_name, city_weather_data_array[i].city_name);
            }
        }
    } else if (strcmp(field, "temp") == 0) {
        for (int i = 0; i < num_cities; i++) {
            if (city_weather_data_array[i].temperature < *min_value) {
                *min_value = city_weather_data_array[i].temperature;
                strcpy(min_city_name, city_weather_data_array[i].city_name);
            }
            if (city_weather_data_array[i].temperature > *max_value) {
                *max_value = city_weather_data_array[i].temperature;
                strcpy(max_city_name, city_weather_data_array[i].city_name);
            }
        }
    } else if (strcmp(field, "humidity") == 0) {
        for (int i = 0; i < num_cities; i++) {
            if (city_weather_data_array[i].humidity < *min_value) {
                *min_value = city_weather_data_array[i].humidity;
                strcpy(min_city_name, city_weather_data_array[i].city_name);
            }
            if (city_weather_data_array[i].humidity > *max_value) {
                *max_value = city_weather_data_array[i].humidity;
                strcpy(max_city_name, city_weather_data_array[i].city_name);
            }
        }
    } else {
        printf("Invalid field. Please enter temp, wind or humidity.\n");
    }
}

int main() {
    int num_cities;
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    // Allocate memory dynamically to hold weather data for each city
    struct CityWeatherData *city_weather_data_array = (struct CityWeatherData*) malloc(num_cities * sizeof(struct CityWeatherData));

    // Get weather data for each city from user
    for (int i = 0; i < num_cities; i++) {
        printf("\nCity %d:\n", i+1);
        printf("Enter city name: ");
        scanf("%s", city_weather_data_array[i].city_name);
        printf("Enter temperature: ");
        scanf("%f", &city_weather_data_array[i].temperature);
        printf("Enter wind speed: ");
            scanf("%f", &city_weather_data_array[i].wind_speed);
    printf("Enter humidity: ");
    scanf("%f", &city_weather_data_array[i].humidity);
}

// Display weather data for all cities in a table
printf("\nWeather data for all cities:\n");
printf("%-20s%-15s%-15s%-15s\n", "City", "Temperature", "Wind Speed", "Humidity");
for (int i = 0; i < num_cities; i++) {
    printf("%-20s%-15.2f%-15.2f%-15.2f\n", city_weather_data_array[i].city_name, city_weather_data_array[i].temperature, city_weather_data_array[i].wind_speed, city_weather_data_array[i].humidity);
}

// Get the weather field for which user wants to find minimum and maximum values
char field[10];
printf("\nEnter the field to find minimum and maximum values (temp, wind, humidity): ");
scanf("%s", field);

// Find the minimum and maximum values for the specified weather field
float min_value, max_value;
char min_city_name[MAX_CITY_NAME_LENGTH], max_city_name[MAX_CITY_NAME_LENGTH];
findMinMax(city_weather_data_array, num_cities, field, &min_value, &max_value, min_city_name, max_city_name);

// Display the minimum and maximum values and corresponding city names
printf("\nMinimum value: %.2f (city: %s)\n", min_value, min_city_name);
printf("Maximum value: %.2f (city: %s)\n", max_value, max_city_name);

// Free the dynamically allocated memory
free(city_weather_data_array);

return 0;
}
