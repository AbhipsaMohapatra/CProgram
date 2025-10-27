#include <stdio.h>

void func1(int row, int col, int a[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            a[i][j]++;
        }
       
    }
}
void func2(int row, int col, int (*p)[col]) // this is p[0]
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            p[i][j]++;
        }
        
    }
}
void fun3(int row, int col, int *p)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            (*p)++;
            p++;
        }
       
    }
}
void fun4(int row, int col, int *p)
{
    for (int i = 0; i < row*col; i++)
    {
        
            (*p)++;
            p++;
        
       
    }
}
void func5(int row, int col, int (*p)[col]) // this is a[0] address
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            (*p)[j]++;
        }
        p++;
        
    }
}

int main()
{
    int row = 2, col = 3;
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

    func1(row, col, a);
    printf("After calling func1() \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
    func2(row, col, a);
    printf("After calling func2() \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
    fun3(row, col, a[0]);
    printf("After calling func3() \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
    fun4(row, col, &a[0][0]);
    printf("After calling func4() \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
     func5(row, col, a);
    printf("After calling func5() \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}