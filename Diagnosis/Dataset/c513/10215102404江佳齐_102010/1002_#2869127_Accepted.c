#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;char s[61];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%s",s);
        int a[128];long long ans=0;
        int digit=0,N=1,j;char *p=s;
        for (int j=0;j<128;j++) a[j]=-1;
        a[*p]=1;
        while(*++p)
        {
            if(a[*p]==-1)
            {
                a[*p]=digit;
                digit=digit?digit+1:2;
                N++;
            }

        }
        if(N<2) N=2;
        p=s;
        while (*p) ans=ans*N+a[*p++];
        printf("case #%d:\n",i);
        printf("%lld\n",ans);
    }
    return 0;
}