#include <stdio.h>
void MyStrcpy(char *dest, char *src);

int main(){
    char str[]="ILoveSUSTech", dest[15];
    MyStrcpy(dest, str);
    printf("Source String: %s\n",str);
    printf("Destination String: %s\n",dest);
    return 0;
}

void MyStrcpy(char *dest, char *src){
    while (*src != '\0'){
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}
