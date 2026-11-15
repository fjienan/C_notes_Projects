#include <stdio.h>
#define TEMP_FEVER 37.3
typedef struct student{
    int stu_num;
    char name[50];
    float temp;
} STU;

void check_fever(STU stud);

int main(){
    STU stu[10] = {{1, "Jack", 36.5},{2, "Tim", 37.6},{3, "Steve", 38.0},{4, "Mara", 36.9},{5, "Paula", 38.8},{6, "Emma", 35.4},{7, "David", 40.0},{8, "Tyler", 37.9}, {9, "Noah", 36.8}, {10, "Daniel", 37.4}};
    for (int i = 0; i < sizeof(stu)/sizeof(stu[0]); i++){
        check_fever(stu[i]);
    }
    return 0;
}

void check_fever(STU stud){
    if (stud.temp > TEMP_FEVER){
        printf("Student %s with number %d has a fever\n",stud.name, stud.stu_num);
    }
}