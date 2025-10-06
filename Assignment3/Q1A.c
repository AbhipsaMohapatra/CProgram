# include <stdio.h>
int main(){
    int n;
    printf("Enter the length of array ");

    scanf("%d",&n);
    if(n<0){
        printf("Invalid Array Length");
        return 0;
    }
    int arr [n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max = arr[0];
    int min = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            min=max;
            max=arr[i];
        }
        else if(arr[i]>min && arr[i]!=max){
            min = arr[i];
        }
    }
    printf("Largest %d and Second Largest %d" ,max,min);
}