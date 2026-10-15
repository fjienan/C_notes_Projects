#include <stdio.h>
int main(){
    float array[5]={0.4f, 0.2f, 1.6f, 4.6f, 9.5};
    float min = array[0],max = array[0];
    for (int i = 0; i < 5; i++){
        if (array[i] <= min){
            min = array[i];
        }
        if (array[i] >= max){
            max = array[i];
        }
    }
    printf("the maximal number is %f\nthe minimal number is %f\n", max, min);
    return 0;
}