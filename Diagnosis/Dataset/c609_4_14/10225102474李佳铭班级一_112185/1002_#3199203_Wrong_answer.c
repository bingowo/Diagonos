#include <stdio.h>
#include <stdlib.h>
#define N 100

int length1(int a)
{
    int sum = 1;
    int max = 0;
    int b = a % 2;
    do
    {
        if(b != a % 2)
        {
            sum++;
            b = a % 2;
        }
        else
        {
            max = (max > sum ) ? max : sum;
            sum = 1;
        }
    }while(a /= 2);
    return (max > sum ) ? max : sum;
}

int main()
{
    int n;
    int a[N];
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d",length1(a[i]));
    }

    return 0;
}