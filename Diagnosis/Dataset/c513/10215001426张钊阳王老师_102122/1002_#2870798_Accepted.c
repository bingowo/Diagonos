#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,i,j,k;
    int a[128];
    scanf("%d",&m);
    for(j=0;j<m;j++)
    {
        char s[61];
        scanf("%s",s);
        for (i=0;i<128;i++) a[i]=-1;
        int digit=0,N=1;
        char *p=s;
        a[*p]=1;
        while (*++p)
            if (a[*p]==-1)
            {
                a[*p]=digit;
                digit=digit?digit+1:2;
                N++;
            }
            if (N<2) N=2;
            long long ans=0;
            p=s; while (*p) ans=ans*N+a[*p++];
            printf("case #%d:\n",j);
            printf("%lld\n",ans);
    }
    return 0;
}