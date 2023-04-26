#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int i,j,T;int a[4]={1,2,4,8},n;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%d",&n);
        int k=n/4,d=n%4;
        long long sum;
        sum=pow(a[4],k);
        sum+=a[d];
        printf("%lld\n",sum);
    }
}