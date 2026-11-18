#include <stdio.h>

typedef struct student{
    char name[50];
    int course1;
    int course2;
    int course3;
} Student;

int main(void){
    Student students[] = {
        {"张三", 85, 90, 75},
        {"李四", 80, 70, 60},
        {"王五", 88, 77, 66},
        {"赵六", 90, 80, 70},
        {"孙七", 85, 75, 65},
        {"周八", 78, 88, 98},
        {"吴九", 82, 92, 72},
        {"郑十", 76, 86, 96}
    };
    int n = sizeof(students) / sizeof(students[0]);
    FILE *fp = fopen("students_scores.csv", "w");
    if (fp == NULL){
        perror("students_scores.csv");
        return 1;
    }

    if (fprintf(fp, "Name,Course 1,Course 2,Course 3\n") < 0){
        perror("Write header");
        fclose(fp);
        return 1;
    }
    for (int i = 0; i < n; i++){
        if (fprintf(fp, "%s,%d,%d,%d\n", students[i].name,
                    students[i].course1, students[i].course2,
                    students[i].course3) < 0){
            perror("Write student scores");
            fclose(fp);
            return 1;
        }
    }
    if (fclose(fp) != 0){
        perror("Close students_scores.csv");
        return 1;
    }
    printf("Student scores saved to students_scores.csv\n");
    return 0;
}
