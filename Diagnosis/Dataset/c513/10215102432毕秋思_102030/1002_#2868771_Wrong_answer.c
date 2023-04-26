#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i,j;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
        char s[61];
        scanf("%s",&s);
        int a[128];
        for(j=0;j<128;j++)
            a[j]=-1;
        int digit=0,N=1;
        char *p=s,*q=s;
        a[*p]=1;
        while(*++p)
        {
            if(a[*p]==-1)
            {
                while(*++q)
                {
                    if(s[*p]==s[*q]) a[*p]=a[*q];
                    else
                    {
                        a[*p]=digit;
                        digit=digit?digit+1:2;
                        N++;
                    }
                }
            }
            if(N<2) N=2;
        }
        long long ans=0;
        p=s;
        while(*p)
            ans=ans*N+a[*p++];
        printf("case #");
        printf("%d",i);
        printf(":\n");
        printf("%lld\n",ans);
    }
    return 0;
}
