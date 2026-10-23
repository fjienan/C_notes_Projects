#include <stdio.h>
int my_strlen(char *str);

int main(){
    char str[]="ILoveSUSTech";
    int len;
    len = my_strlen(str);
    printf("Length of string \"%s\" is %d\n",str, len);
    return 0;
}

int my_strlen(char *str){
    int len = 0;
    char *b = str;
    while (*b != '\0'){
        len++;
        b++;
    }
    return len;
}