#include <stdio.h>
#include <string.h>
#define SIZE 100
int count(char a[])
{
    char curr = a[0];
    int count = 0;
    while (curr != '\0')
    {
        count++;
        curr = a[count];
    }
    return count;
}
void copy(char *p1, char *p2)
{
    int c = 0;
    while (*p1 != '\0')
    {
        c++;
        p1++;
    }
    while (*p2 != '\0')
    {
        strcat(p1, p2);
        p2++;
        p1++;
    }
    fputs(p1, stdout);
}

int main()
{
    char s[SIZE];
    char a[SIZE];

    char b[SIZE];

    printf("Enter the String ");
    // scanf("%s",a);
    // printf("Your string is \t %s",a);
    printf("Enter your strings \n");
    fgets(a, SIZE, stdin);
    fgets(b, SIZE, stdin);
    // Read input into 'a'
    // fputs(a, stdout);

    // char k[] = "Hello";
    printf("%d \n", count(a));
    copy(a,b);

    return 0;
}