#include<stdio.h>
void cal_bits(int x);

int main(){
    int number = 12345;
    printf("The digits of the integer are: ");
    cal_bits(number);
    printf("\n");
    return 0;
}

void cal_bits(int x){
    int residue, y;
    residue = x % 10;
    y = (x - residue)/10;
    if (y == 0){
        printf("%d ",residue);
        return;
    };
    cal_bits(y);
    printf("%d ",residue);
}