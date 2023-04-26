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
    int numm[101];
    for (int j = 0; j < i; j++)
    {
        numm[j] = num[j];
        for (int z = j + 1; z < i; z++)
        {
            if (num[j] == num[z])
                numm[j] = 0;
        }
    }

    if (flag == 'A')
    {
        for (int j = 0; j < i-1; j++)
        {
            if(numm[j]!=0)
                printf("%d ", num[j]);
        }
        printf("%d\n", num[i - 1]);
    }
    else if(flag=='D')
    {
        for (int j = i-1; j > 0; j--)
        {
            if (numm[j] != 0)
                printf("%d ", num[j]);
        }
        printf("%d\n", num[0]);
    }
    return 0;
}
