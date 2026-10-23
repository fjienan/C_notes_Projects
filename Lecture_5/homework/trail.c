#include<stdio.h>
int redefine(int a, int b);

int main(){
    int x = 1, y = 4, z;
    printf("x is %d\n",x);
    z = redefine(x, y);
    printf("x is %d\n",x);
    return 0;
}

int redefine (int a, int b){
    a = b;
    return a;
}