#include<stdio.h>
void reverse_array(int* array, int size);

int main(){
    int a[8]={0, 10, 20, 30, 40, 50, 60, 70};
    printf("Original array: ");
    for (int i = 0; i < 8; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    reverse_array(a, 8);
        printf("Reversed array: ");
    for (int i = 0; i < 8; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}

void reverse_array(int* array, int size){
    for(int i = 0; i < (int)size/2; i++){
        int temp;
        temp = *(array+i);
        *(array+i) = *(array+size-1-i);
        *(array+size-1-i) = temp;
    }
}