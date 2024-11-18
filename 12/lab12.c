// These are the only libraries allowed to be used:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Changing struct members (data types, names, size) is not allowed.
typedef struct {
    char date[11];              // Date in the format: "YYYY-MM-DD"
    float *temperature;         // Array for hourly temperatures 24 values
    float *windspeed;           // Array for hourly windspeeds 24 values
} weatherDay; // Changing struct name is not allowed.

// Changing arrayAlloc() function is not allowed.
float* arrayAlloc(int size) {
    return (float*) malloc(size * sizeof(float));
}

// You can use this structAlloc() function if you think you need it.
//weatherDay* structAlloc() {
//    return (weatherDay*) malloc(sizeof(weatherDay));
//}

// Changing declarations for the following functions is not allowed.
// Exception: int numberDays - you can remove it, if it is not necessary in your functions' implementations.
// You must use all of these functions in your code.
// You are allowed to declare and define your own additional functions.

// int countDays(FILE *file);
// void loadWeatherData(FILE *file, weatherDay *Days, int numberDays);
// void aveTemp(weatherDay *Days, int numberDays);
// void modifyTemp(weatherDay *Days, int numberDays);
// void modifyWind(weatherDay *Days, int numberDays);
// void findMaxTemp(weatherDay *Days, int numberDays);
// void findMinTemp(weatherDay *Days, int numberDays);
// void findMaxWind(weatherDay *Days, int numberDays);
// void findMinWind(weatherDay *Days, int numberDays);

// Changing this function's signature is not allowed!
int countDays(FILE *file) {

    // TODO: Function to count number of days
    int numberDays = 0;
    char temp[88];

    while(fgets(temp, sizeof(temp), file)!=NULL)
        numberDays++;
    return numberDays/24;
}

// Changing this function's signature is not allowed.
// Exception: int numberDays - you can remove it, if it is not necessary in your function's implementation
void loadWeatherData(FILE *file, weatherDay *Days, int numberDays) {

    // TODO: Function to load data from CSV file to Days.

    // Call arrayAlloc from this function to allocate arrays for temperature and windspeed.
    // Use pointer arithmetic to instead of array indexing with [].
    char temp[88];
    int day=-1, hour=0;

    while(fgets(temp, sizeof(temp), file)!=NULL){
        char date[11];
        float temperature, windspeed;
        sscanf(temp, "%10[^T]T%*[^,],%f,%f", date, &temperature, &windspeed);

        if(hour==0){
            day++;
            strcpy((Days+day)->date, date);
            (Days+day)->temperature=arrayAlloc(24);
            (Days+day)->windspeed=arrayAlloc(24);
        }

        *((Days+day)->temperature+hour)=temperature;
        *((Days+day)->windspeed+hour)=windspeed;

        hour=(hour+1)%24;
    }
}

// Changing this function's signature is not allowed.
// Exception: int numberDays - you can remove it, if it is not necessary in your function's implementation
void aveTemp(weatherDay *Days, int numberDays) {
    char date[11];
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%10s", date);

    // TODO: Function to calculate average temperature for a ata from CSV file to Days.

    // Use pointer arithmetic to instead of array indexing with []. 

    //printf("Average temperature for %s: %.2f\n", date, sum / 24);
    for(int i=0; i<numberDays; i++){
        if(strcmp((Days+i)->date, date)==0){
            float sum=0;
            
            for(int j=0; j<24; j++){
                printf("%f\n", *((Days+i)->temperature+j));
                sum+=*((Days+i)->temperature+j);
            }
            printf("Average temperature for %s: %.2f\n", date, sum / 24);
        }
    }
}

// Changing this function's signature is not allowed.
// Exception: int numberDays - you can remove it, if it is not necessary in your function's implementation
void modifyTemp(weatherDay *Days, int numberDays) {
    char date[11];
    int hour;
    float newTemp;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%10s", date);
    printf("Enter hour (0-23): ");
    scanf("%d", &hour);
    printf("Enter new temperature: ");
    scanf("%f", &newTemp);

    // TODO: Function to modify temperature value for a specific day and hour.

    // Use pointer arithmetic to instead of array indexing with []. 

    //printf("Temperature updated.\n");
    for(int i=0; i<numberDays; i++){
        if(strcmp((Days + i)->date, date)==0){
            *((Days + i)->temperature+hour)=newTemp;
            printf("Temperature updated.\n");
        }
    }
}

// Changing this function's signature is not allowed.
// Exception: int numberDays - you can remove it, if it is not necessary in your function's implementation
void modifyWind(weatherDay *Days, int numberDays) {
    char date[11];
    int hour;
    float newWind;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%10s", date);
    printf("Enter hour (0-23): ");
    scanf("%d", &hour);
    printf("Enter new windspeed: ");
    scanf("%f", &newWind);

    // TODO: Function to modify windspeed value for a specific day and hour.

    // Use pointer arithmetic to instead of array indexing with []. 
    
    //printf("Windspeed updated.\n");
    for(int i=0; i<numberDays; i++){
        if(strcmp((Days+i)->date, date)==0){
            *((Days+i)->windspeed+hour)=newWind;
            printf("Windspeed updated.\n");
        }
    }
}

// Changing this function's signature is not allowed.
// Exception: int numberDays - you can remove it, if it is not necessary in your function's implementation
void findMaxTemp(weatherDay *Days, int numberDays) {

    // TODO: Function to find maximum temperature value across all days and hours.

    // Use pointer arithmetic to instead of array indexing with [].
    float maxTemp=-100.0;
    char maxTempDate[11];
    int maxTempHour=-1;

    for(int i=0; i<numberDays; i++){
        for(int j=0; j<=23; j++){
            if (*((Days+i)->temperature+j)>maxTemp){
                maxTemp=*((Days+i)->temperature+j);
                strcpy(maxTempDate, (Days+i)->date);
                maxTempHour=j;
            }
        }
    }
    printf("Max temperature: %.2f on:\n %s at hour %d\n", maxTemp, maxTempDate, maxTempHour);
}

// Changing this function's signature is not allowed.
// Exception: int numberDays - you can remove it, if it is not necessary in your function's implementation
void findMinTemp(weatherDay *Days, int numberDays) {

    // TODO: Function to find maximum temperature value across all days and hours.

    // Use pointer arithmetic to instead of array indexing with [].
    float minTemp=100.0;
    char minTempDate[11];
    int minTempHour=-1;

    for(int i=0; i<numberDays; i++){
        for(int j=0; j<=23; j++){
            if (*((Days+i)->temperature+j)<minTemp){
                minTemp=*((Days+i)->temperature+j);
                strcpy(minTempDate, (Days+i)->date);
                minTempHour=j;
            }
        }
    }
    printf("Min temperature: %.2f on:\n %s at hour %d\n", minTemp, minTempDate, minTempHour);
}

// Changing this function's signature is not allowed.
// Exception: int numberDays - you can remove it, if it is not necessary in your function's implementation
void findMaxWind(weatherDay *Days, int numberDays) {

    // TODO: Function to find maximum windspeed value across all days and hours.

    // Use pointer arithmetic to instead of array indexing with [].
    float maxWind=-100.0;
    char maxWindDate[11];
    int maxWindHour=-1;

    for(int i=0; i<numberDays; i++){
        for(int j=0; j<=23; j++){
            if(*((Days+i)->windspeed+j)>maxWind){
                maxWind=*((Days+i)->windspeed+j);
                strcpy(maxWindDate, (Days+i)->date);
                maxWindHour=j;
            }
        }
    }
    printf("Max windspeed: %.2f on:\n", maxWind);
    for(int i=0; i<numberDays; i++){
        for(int j=0; j<=23; j++){
            if(*((Days+i)->windspeed+j)>maxWind){
                printf("%s at hour %d\n", maxWindDate, maxWindHour);
                maxWind=*((Days+i)->windspeed+j);
                strcpy(maxWindDate, (Days+i)->date);
                maxWindHour=j;
            }
        }
    }
}

// Changing this function's signature is not allowed.
// Exception: int numberDays - you can remove it, if it is not necessary in your function's implementation
void findMinWind(weatherDay *Days, int numberDays) {

    // TODO: Function to find maximum windspeed value across all days and hours.

    // Use pointer arithmetic to instead of array indexing with [].
    float minWind=100.0;
    char minWindDate[11];
    int minWindHour=-1;

    for(int i=0; i<numberDays; i++){
        for(int j=0; j<=23; j++){
            if(*((Days+i)->windspeed+j)<minWind){
                minWind=*((Days+i)->windspeed+j);
                strcpy(minWindDate, (Days+i)->date);
                minWindHour=j;
            }
        }
    }
    printf("Min windspeed: %.2f on:\n", minWind); 
    for(int i=0; i<numberDays; i++){
        for(int j=0; j<=23; j++){
            if(*((Days + i)->windspeed+j)==minWind){
                printf("%s at hour %d\n", minWindDate, minWindHour);
                minWind=*((Days+i)->windspeed+j);
                strcpy(minWindDate, (Days+i)->date);
                minWindHour=j;
            }
        }
    }
    
}

// Changing main() is not allowed!
int main() {

    FILE *file = fopen("weather_data.csv", "r");
    if (file == NULL) {
        printf("Problem opening file.");
        return 1;
    }
    
    printf("File opened successfully.");

    int numberDays = countDays(file);
    rewind(file);       // reinitialize file position to the beginning of the file https://www.tutorialspoint.com/c_standard_library/c_function_rewind.htm

    weatherDay *Days = (weatherDay*) malloc(numberDays * sizeof(weatherDay));
    loadWeatherData(file, Days, numberDays);

    fclose(file);

    int option;
    do {
        printf("\nMenu:\n");
        printf("1 - Count total number of Days;\n");
        printf("2 - Calculate average temperature for a specific day;\n");
        printf("3 - Modify temperature data for a specific day;\n");
        printf("4 - Modify windspeed data for a specific day;\n");
        printf("5 - Find day(s) with max temperature;\n");
        printf("6 - Find day(s) with min temperature;\n");
        printf("7 - Find day(s) with max windspeed;\n");
        printf("8 - Find day(s) with min windspeed;\n");
        printf("9 - Exit.\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Total number of Days: %d\n", numberDays);
                break;
            case 2:
                aveTemp(Days, numberDays);
                break;
            case 3:
                modifyTemp(Days, numberDays);
                break;
            case 4:
                modifyWind(Days, numberDays);
                break;
            case 5:
                findMaxTemp(Days, numberDays);
                break;
            case 6:
                findMinTemp(Days, numberDays);
                break;
            case 7:
                findMaxWind(Days, numberDays);
                break;
            case 8:
                findMinWind(Days, numberDays);
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 9);

    for (int i = 0; i < numberDays; i++) {
        free((Days + i)->temperature);
        free((Days + i)->windspeed);
    }
    free(Days);

    return 0;
}