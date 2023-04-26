#include <stdio.h>

int main()
{
    long long num[75];
    int t,i,n;
    num[0]=0;
    num[1]=1;
    num[2]=1;
    for(i=3;i<75;i++)
        num[i]=num[i-1]+num[i-2]+num[i-3];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        printf("case #%lld:\n",i);
        printf("%lld\n",num[n]);
    }
    return 0;
}
