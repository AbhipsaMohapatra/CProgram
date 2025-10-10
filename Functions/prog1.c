// User defined function 
# include <stdio.h>
void fun1(int p){
    p++;
    printf("Updated Value %d",p );
    

}
void fun2(int p[],int n){
    for(int i=0;i<n;i++){
        p[i]++;
    
    }
    printf("Updated Values ");
    for(int i=0;i<n;i++){
        printf("%4d",p[i]);
    }
    
}
int main(){
    int a[100];
    int n;
    printf("Enter number of elements ");
    scanf("%d",&n);
    printf("\nEnter Values :");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    fun1(a[0]); //Call By Value
    printf("\n After function calling value = %d \n",a[0]);
    fun2(a,n);

    printf("\nAfter updateion there is no change");

    for(int i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
}