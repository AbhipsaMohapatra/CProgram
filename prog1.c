#include <stdio.h>
#include <string.h>
#define SIZE 100


int main(){
    char s[SIZE];
    char a[] = {'H','e','l','l','o'};
    char b[] = "Hello";
    //usage of strlen()

    // printf("Length of a array = %d \t \n %s ",strlen(a),a);
    printf("Length of b array = %d , \n %s is the string  \t",strlen(b),b);

    //copy the array
    // strncpy(s,b,2);
    // printf("String in s[]= %s \n",s);

    //concat the array
    // strcat(s,b);
    // printf("String s is %s ",s);

    // strcat(s," okay ");
    strncat(s,b,5);
    printf("String s is after n cat  %s \n",s);
   if(strncmp(s,b,5)==0){//strcp strcmp
    printf("Strings in s[] and b[] are equal ");
   }
   else{
    printf("Strings s[] and b[] are not equal ");
   }
   


    return 0;

}