#include<stdio.h>
void swap(int *var1, int *var2);

int main(){
    int a = 1, b = 5;
    printf("%d and %d\n",a, b);
    swap(&a, &b);
    printf("%d and %d\n",a, b);
    return 0;
}

void swap(int *var1, int *var2){
    int temp;
    temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}