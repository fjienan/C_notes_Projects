#include <stdio.h>
#include <stdlib.h>
int* Rabbit_Chicken(int* heads, int* legs);

int main(void){
    // example 1
    int legs = 22, heads = 7;
    printf("total heads (n): %d, total legs (m): %d\n",heads,legs);
    int* num;
    num = Rabbit_Chicken(&heads, &legs);
    if(num == NULL){
        printf("No Answer!\n");
    }
    else{
        printf("Number of Chickens: %d\n",num[0]);
        printf("Number of Rabbits: %d\n",num[1]);
    }
    free(num);
    // example 2
    legs = 25;
    heads = 9;
    printf("total heads (n): %d, total legs (m): %d\n",heads,legs);
    num = Rabbit_Chicken(&heads, &legs);
    if(num == NULL){
        printf("No Answer!\n");
    }
    else{
        printf("Number of Chickens: %d\n",num[0]);
        printf("Number of Rabbits: %d\n",num[1]);
    }
    free(num);
    return 0;
}

int* Rabbit_Chicken(int* heads, int* legs){

    int* num;
    num = (int*)calloc(2,sizeof(int));
    if ((4*(*heads)-(*legs))%2 != 0){
        free(num);
        return NULL;
    }
    else if((4*(*heads)-(*legs))/2 < 0 || (4*(*heads)-(*legs))/2 > *heads){
        free(num);
        return NULL;
    }
    else{
        *num = (4*(*heads)-*legs)/2;
        *(num+1) = *heads - *num; 
    }

    return num;
}
