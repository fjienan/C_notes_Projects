#include <stdio.h>
int main(){
    int year = 2025, month = 9, day = 28;
    int tag = 0, date = 0;
    // check whether this is leap year or not
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0){
        printf("%d IS leap year\n",year);
        tag = 1;
    }
    else {
        printf("%d is NOT leap year\n",year);
        tag = 0;
    }
    for (int i = 1; i < month; i++){
        if (i <= 7){
            if (i == 2){
                date += 28;
                if (tag){
                 date += 1;  
                }
            }
            else if (i != 2 && i%2 != 0){
                date += 31;
            }
            else {
                date += 30;
            }
        }
        else {
            if (i%2 == 0){
                date += 31;
            }
            else {
                date += 30;
            }
        }
    }
    date += day;
    printf("%d %d %d is the %d-th day of %d\n",year, month, day, date, year);
    return 0;
}