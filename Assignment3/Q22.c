#include <stdio.h>
int main()
{
    int n;
    int num;
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
        printf("Enter the integers of the array of size %d in ascending order ", n);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to insert ");
    scanf("%d", &num);
    int ans[n + 1];
    if (n == 0)
    {
        ans[0] = num;
    }
    else
    {
        int j = 1;
        int ind = 0;
        int pos = n;
        if (num < arr[0])
        {
            pos = 0;
        }
        else if (num > arr[n - 1])
        {
            pos = n;
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {

                if (num >= arr[i] && num < arr[j])
                {
                    pos = i + 1;
                }

                j++;
            }
        }

        for (int i = 0; i < n + 1; i++)
        {
            if (i < pos)
            {
                ans[i] = arr[i];
            }
            else if (i == pos)
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