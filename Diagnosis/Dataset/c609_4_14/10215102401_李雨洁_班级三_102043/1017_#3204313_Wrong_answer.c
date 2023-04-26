#include <stdio.h>
#include <string.h>
void F(int a[],int n)//升序
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int t = a[j];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}
int main()
{
    char flag;
    scanf("%c", &flag);
    int num[101];
    int i = 0;
    while (scanf("%d", &num[i]) != EOF)
    {
        i++;
    }
    F(num, i);
    if (flag == 'A')
    {
        for (int j = 0; j < i-1; j++)
        {
            printf("%d ", num[j]);
        }
        printf("%d\n", num[i - 1]);
    }
    else
    {
        for (int j = i-1; j > 0; j--)
        {
            printf("%d ", num[j]);
        }
        printf("%d\n", num[0]);
    }
    return 0;
}
