#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    long long x,y;
    long long dis;
    scanf("%lld %lld",&x,&y);
    long long p=x,q=y;
    if(p<0) p=-p;
    if(q<0) q=-q;
    dis=p+q;
    if(dis==0) printf("0\n");
    else if(dis%2==0) printf("-1\n");
    else
    {
        int ans=0;
        long long k=1;
        long long cnt=0;
        while(cnt<dis)
        {
            cnt+=k;
            k*=2;
            ans++;
        }
        printf("%d",ans);
    }
    return 0;
}
