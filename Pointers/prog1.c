#include <stdio.h>

int main(){
    // int a=100;
    // char b='a';
    // float c=23.4;
    // int *p1;
    // char *p2;
    // float *p3;
    // printf("\nSize of p1 %ld ",sizeof(p1));
    // printf("\nSize of p1 %ld ",sizeof(p2));
    // printf("\nSize of p1 %ld ",sizeof(p3));
    // p1=&a;
    // p2=&b;
    // p3=&c;
    // printf("\n the address of a is %p",&a);
    // printf("\nThe address of a %p",p1);
    // printf("\nThe value of a is %d",a);
    // printf("\n The value of a using p %d",*p1);
    // p1++;
    // printf("\nThe p1 is %ld ",p1);
    // printf("\nThe p1 is %ld ",p1+3);
    // printf("\nThe p1 is %ld ",p1+++2);
    // printf("\nThe p1 is %ld ",p1);
    // int a[] = {1,2,3,4};
    // int *p=&a[3];
    // for(int i=3;i>=0;i--){
    //     printf("%d th value is %d\n",i,*p--);
       
    // }
    int n;
    printf("Enter the length of array ");

    scanf("%d",&n);
    if(n<=0){
        printf("Invalid Array Length");
        return 0;
    }
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    int i=0;
    int j=n-1;
    int *p1= &a[0];
    int *p2 = &a[n-1];
    while(p1<=p2){
       
       int temp = *p1;
       *p1 = *p2;
       *p2 = temp;
        p1++;
        p2--;
    }

    for (int k=0;k<n;k++){
        printf("%d ",a[k]);
    }


    

    return 0;



}