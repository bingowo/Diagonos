#include <stdio.h>

int main()
{
    int k,n; scanf("%d %d",&k,&n);
    int num[120] = {0,0,0,0,0,0,0,0,0,0,0,0,1};
    int sum = 0;
    for (int i=0;i<k;i++) sum += num[12-i];
    for (int i=13;i<=n+10;i++)
    {
        num[i] = sum;
        sum = sum + num[i] - num[i-10];
    }
    printf("%d\n",num[n+10]);
    return 0;
}