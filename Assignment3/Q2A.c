# include <stdio.h>
int main(){
     int n;
    printf("Enter the length of array ");

    scanf("%d",&n);
    if(n<=0){
        printf("Invalid Array Length");
        return 0;
    }
    int arr [n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int i=0;
    int j = n-1;
    //Odd Then Even
    while(i<j){
        if(arr[i]%2==0 ){
            if(arr[j]%2!=0){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j]=temp;
                i++;
               

            }
           j--;
            
            
        }
        else if(arr[j]%2!=0){
           i++;
        }
        else{
            i++;
            j--;
        }
    }
    printf("The Elements are \n");

    for(int i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }
    printf("\n");
    return 0;
    

}