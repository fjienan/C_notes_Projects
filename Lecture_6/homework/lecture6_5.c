#include <stdio.h>
#include <stdlib.h>
float* createScoreBook(float* book);
int main(){
    float* book = NULL;
    book = createScoreBook(book);
    int lengh = *book;
    for (int i = 1; i < lengh - 1; i++){
        printf("Score[%d] = %.1f\n",i-1, book[i]);
    }
    printf("Average = %.2f \n",book[lengh - 1]);
    book = createScoreBook(book);
    return 0;
}

float* createScoreBook(float* book){
    if (book != NULL){
        free(book);
        printf("Memory freed successfully\n");
        return NULL;
    }
    else{
    float* scorebook;
    float sum = 0;
    float a[5]={78.5, 82.0, 91.5, 88.0, 76.0};
    int lengh = (int)sizeof(a)/sizeof(a[0]);
    scorebook = (float*)malloc((lengh+2)*sizeof(float));
    *(scorebook) = (float)(lengh + 2);

    for (int i = 1; i <= lengh; i++){
        *(scorebook+i) = a[i-1];
        sum += a[i-1];
    }
    *(scorebook+lengh+1) = sum/(float)lengh;
    return scorebook;   
    }
}