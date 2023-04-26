#include <stdlib.h>
#include <stdio.h>
//迭代法
int main()
{
    int k,n,i;
    scanf("%d %d",&k,&n);
    int ar[n + 10];
    for(i = 0;i <= 10;i++)
        ar[i] = 0;
    ar[11] = 1;
    for(i = 10;i <= n + 9;i++)
    {
        for(int j = 1;j <= k;j++)
            ar[i] += ar[i - k];
    }
    printf("%d\n",ar[n + 9]);
    return 0;
}