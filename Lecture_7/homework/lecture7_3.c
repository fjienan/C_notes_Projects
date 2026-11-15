#include <stdio.h>
#include <string.h>
#define TEMP_CRITERION 30.0f
typedef enum weekday {MON, TUE, WED, THU, FRI, SAT, SUN} Weekday;

typedef struct temperature_reocrd{
    Weekday dayEnum;
    char dayName[50];
    float temperature;
} TemperatureRecord;

void printHighTemperature(TemperatureRecord weektemp[], int n);

Weekday Name2Enum(char name[]);

int main(){
    TemperatureRecord weektemp[] = {{MON, "Monday", 28.5}, {TUE, "Tuesday", 31.3}, {WED, "Wednesday", 29}, {THU, "Thursday", 35.2}, {FRI, "Friday", 30.5}, {SAT, "Saturday", 25.0}, {SUN, "Sunday", 32.8}};
    int n = sizeof(weektemp)/sizeof(weektemp[0]);
    for (int i = 0; i < n; i++){
        Weekday day = Name2Enum(weektemp[i].dayName);
        if (day == weektemp[i].dayEnum){
            continue;
        }
        else{
            printf("\nERROR: the dayEnum does not match the dayName in the weektemp array!\nPlease check!!\n\n");
            return 1;
        }
    }
    printf("\nDEBUG: the dayEnum matches the dayName in the weektemp array!!!\n\n");

    printHighTemperature(weektemp, n);
    return 0;
}
Weekday Name2Enum(char name[]){
    if (strcmp(name, "Monday")==0){
        return MON;
    }
    else if(strcmp(name, "Tuesday")==0){
        return TUE;
    }
    else if(strcmp(name, "Wednesday")==0){
        return WED;
    }
    else if(strcmp(name, "Thursday")==0){
        return THU;
    }
    else if(strcmp(name, "Friday")==0){
        return FRI;
    }
    else if (strcmp(name, "Saturday")==0){
        return SAT;
    }
    else{
        return SUN;
    }

}

void printHighTemperature(TemperatureRecord weektemp[], int n){
    for (int i = 0; i < n; i++){
        if (weektemp[i].temperature > TEMP_CRITERION){
            printf("High temperature on %s: %.2f°C\n",weektemp[i].dayName, weektemp[i].temperature);
        }
    }
}