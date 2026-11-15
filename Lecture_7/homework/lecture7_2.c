#include <stdio.h>
#define TEMP_FEVER 37.3
typedef struct student{
    int stu_num;
    char name[50];
    float temp;
} Student;

void sortStudent(Student stu[], int n);
void swap(Student* a, Student* b);

int main(){
    Student stu[10] = {{1, "Jack", 36.5},{2, "Tim", 37.6},{3, "Steve", 38.0},{4, "Mara", 36.9},{5, "Paula", 38.8},{6, "Emma", 35.4},{7, "David", 40.0},{8, "Tyler", 37.9}, {9, "Noah", 36.8}, {10, "Daniel", 37.4}};
    int n = sizeof(stu)/sizeof(stu[0]);
    sortStudent(stu, n);
    for (int i = 0; i < n; i++){
        printf("Student %s with number %d, Temperature: %.1f\n",stu[i].name, stu[i].stu_num, stu[i].temp);
    }
    return 0;
}

void swap(Student* a, Student* b){
    Student temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sortStudent(Student stud[], int n){
    for (int i = 1; i < n; i++){
        for (int j = i ; j > 0; j--){
            if (stud[j].temp<=stud[j-1].temp){
                continue;
            }
            else{
                swap(&stud[j],&stud[j-1]);
            }
        }
    }
}