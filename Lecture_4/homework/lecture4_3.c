#include <stdio.h>
int main(){
    int arr[]={3, 5, 20, 5, 88, 22, 36, 26, 55, 2, 66, 4, 33, 98, 42};
    for (int i = 1; i < (int)(sizeof(arr)/sizeof(arr[0])); i++){
        for (int j = i; j > 0; j--){
            if (arr[j] < arr[j-1]){
                int mid;
                mid = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = mid;
            }
            else {
                break;
            }
        }
    }
    printf("the ascendng order is ");
    for (int i = 0; i < (int)(sizeof(arr)/sizeof(arr[0])); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}