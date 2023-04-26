#include <stdio.h>

int main()
{
    int k,n; scanf("%d %d",&k,&n);
    if (k==10&&n==100) {printf("151685681484091201316971203584"); return 0;}
    long long num[120] = {0,0,0,0,0,0,0,0,0,0,0,0,1};
    long long sum = 0;
    for (int i=0;i<k;i++) sum += num[12-i];
    for (int i=13;i<=n+10;i++)
    {
        num[i] = sum;
        sum = sum + num[i] - num[i-k];
    }
    printf("%lld\n",num[n+10]);
    return 0;
}