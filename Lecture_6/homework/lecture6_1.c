#include <stdio.h>
void swap_and_sum(float *var1, float *var2, float *var3);

int main(){
    float a=5.5, b=10.1, c;
    printf("Before Swapping:\n");
    printf("a = %f, b = %f\n",a ,b);
    swap_and_sum(&a, &b, &c);
    printf("After swapping and summing\n");
    printf("a = %f, b = %f, c = %f\n",a ,b ,c);
    return 0;
}

void swap_and_sum(float *var1, float *var2, float *var3){
    float temp;
    temp = *var1;
    *var1 = *var2;
    *var2 = temp;
    *var3 = *var1 + *var2;
}