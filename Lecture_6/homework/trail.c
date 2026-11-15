#include<stdio.h>
#include<stdlib.h>

int main(){
    float a = 1.0, b = 5.0;
    float *ptr = NULL;
    ptr = (float*)calloc(2,sizeof(float));
    *ptr = a;
    *(ptr+1) = b;
    printf("%f and %f\n",ptr[0], ptr[1]);
    free(ptr);
    if (ptr == NULL){
        printf("ptr is NULL\n");
    }
    return 0;
}
