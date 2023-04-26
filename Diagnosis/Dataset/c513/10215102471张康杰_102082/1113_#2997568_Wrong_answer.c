#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//迭代法
int main()
{
    int k,n,i;
    scanf("%d %d",&k,&n);
    int ar[n + 10];
    memset(ar,0,sizeof(int) * (n + 10));
    ar[11] = 1;
    for(i = 10;i <= n + 9;i++)
    {
        for(int j = 1;j <= k;j++)
            ar[i] += ar[i - j];
    }
    printf("%d\n",ar[n + 9]);
    return 0;
}