#include <stdio.h>
int main()
{
    int n;
    int num;
    int ind;
    printf("Enter the length of array ");

    scanf("%d", &n);
    if (n < 0)
    {
        printf("Invalid Array Length");
        return 0;
    }

    int arr[n];
    if (n != 0)
    {
        printf("Enter the integers of the array of size %d ", n);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans[n + 1];
    printf("Enter the number to be inserted ");
    scanf("%d", &num);
    if(n==0){
        printf("The only one index is possible %d",num);
        return 0;
    }
    printf("Enter the index you want to insert ");
    scanf("%d", &ind);
    
    ind=ind-1;

    if (ind >= n + 1 && ind < 0)
    {
        printf(" invalid insert index ");
        return 0;
    }
    else
    {
        for (int i = 0; i < n + 1; i++)
        {
            if (i < ind)
            {
                ans[i] = arr[i];
            }
            else if (i == ind)
            {
                ans[i] = num;
            }
            else
            {
                ans[i] = arr[i - 1];
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        printf("%d \t", ans[i]);
    }
    printf("\n");
    return 0;
}