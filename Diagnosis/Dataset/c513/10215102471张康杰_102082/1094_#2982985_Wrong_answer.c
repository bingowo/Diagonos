#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 122
int cmp(const void*a,const void*b)
{
    int*pt1 = *(int(*)[N])a,*pt2 = *(int(*)[N])b;
    pt1 = pt1 + N - 1,pt2 = pt2 + N - 1;
    for(;;pt1--,pt2--)
    {
        if(*pt1 > *pt2)
            return -1;
        else if(*pt1 < *pt2)
            return 1;
        else
        {
            continue;
        }
    }
}

void Sub(int a[],int b[])
{
    int i,carry = 0;
    for(i = 0;i < N;i++)
    {
        a[i] = a[i] - b[i];
        if(a[i] < 0)
        {
            a[i] += 10;
            a[i + 1]--;
        }
    }
}
int main()
{
    int n,i,len;
    scanf("%d",&n);
    int input[50][N] = {{0}};
    char bigint[N];
    for(i = 0;i < n;i++)
    {
        scanf("%s",bigint);
        len = strlen(bigint);
        for(int j = 0;j < len;j++)
        {
            input[i][j] = bigint[len - j - 1] - '0';
        }
    }
    qsort(input,n,sizeof(int*),cmp);
    Sub(input[n - 1],input[0]);
    int flag = 1;
    for(i = N - 1;i >= 0;i--)
    {
        if(flag && input[n - 1][i] == 0)
            continue;
        else
        {
            flag = 0;
            printf("%d",input[n - 1][i]);
        }
    }
    putchar('\n');
    return 0;
}