#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        long long a=0;
        int b=0,n=0;
        scanf("%lld%d%d",&a,&b,&n);

        long long k=10;
        long long re=1;
        for(int i=1;i<n;i++)
            k*=10;
        for(int i=0;i<b;i++)
            re=(re*a)%k;

        int cnt=0;
        long long t=re;
        do
        {
            t/=10;
            cnt++;
        }while(t>0);
        printf("case #%d:\n",cas);
        if(cnt<n)
            for(int i=0;i<n-cnt;i++)
                printf("0");
        printf("%lld\n",re);
    }
    return 0;
}