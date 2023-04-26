#include <stdio.h>
#include <stdlib.h>

long long num(int i)
{
    long long ans;
    if(i==1) ans=1;
    else if(i==2) ans=2;
    else if(i==3) ans=4;
    else if(i==4) ans=8;
    else ans= num(i-1)+num(i-2)+num(i-3)+num(i-4);
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int k=0;k<T;k++)
    {
        int i;
        scanf("%d",&i);
        long long ans;
        ans=num(i);
        printf("case #%d:\n",k);
        printf("%lld\n",ans);
    }
    return 0;
}
