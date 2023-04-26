#include <stdio.h>

int main()
{
    int count,n,t,k,cnt;
    scanf("%d",&count);
    while(count--)
    {
        cnt=0;
        scanf("%d",&n);
        if(n==0)
        {
            printf("1");continue;
        }
        for(int i=0;i<=n/4;i++)
        {
            t=n-4*i;
            //printf("%d!!",t);
            for(int j=0;j<=t/3;j++)
            {
                k=t-3*j;//printf("%d!",k);
                for(int p=0;p<=k/2;p++)
                {
                    cnt++;
                }
            }
        }
        printf("%d",cnt);
    }
}