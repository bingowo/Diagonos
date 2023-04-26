#include <stdio.h>
int main()
{
    long long int ans[75]={0};
    ans[0]=0;
    ans[1]=1;
    ans[2]=1;
    for(int j=3;j<75;j++)
    {
        ans[j]=ans[j-1]+ans[j-2]+ans[j-3];
    }
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int num;
        scanf("%d",&num);
        printf("%lld\n",ans[num]);
    }
    return 0;
}