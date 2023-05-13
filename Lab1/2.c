#include<stdio.h>
#include<string.h>

int main(){
    char *string;
    int length,i;

    string = "idea without execution is worthless";
    length = strlen(string);

    for(i=0; i<length; i++){
        if (string[i]=='c' || string[i]=='C'){
            printf("The position of c in the string is %d.\n",i);
            return 0;
        }
    }
    printf(" C was not found in the string.");
    return 0;
}