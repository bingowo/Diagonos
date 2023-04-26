#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        char s[61];
        scanf("%s",s);
        int a[128];
        for(int t=0;t<128;t++) a[t]=-1;
        int digit=0,N=1;
        a[0]=1;
        for(int y=1;s[y]!='\0';y++)
        {
            if(a[y]==-1)
            {
                a[y]=digit;
                digit = digit? digit+1:2;
                N++;
            }
        }
        if(N<2) N=2;
        long long result=0;
        for(int y=0;s[y]!='\0';y++)
        {
            result=result*N+a[y];
        }
        printf("case #%d\n",i);
        printf("%lld\n",result);
    }
    return 0;

}