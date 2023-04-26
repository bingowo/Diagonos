#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int kk(char *s);

int main()
{
    int an,ii;
    long long int n;
    char s[61];
    scanf("%d",&an);
    for(ii=0;ii<an;ii++)
    {

        printf("case #%d:\n",ii);
        scanf("%s",s);
        n=kk(s);
        printf("%lld\n",n);
    }
    return 0;
}
long long int kk(char *s)
{
        int digit=0,N=1,i;
        long long int all=0;
        int a[128];
        for (i=0;i<128;i++)
            a[i]=-1;
        char *p=s;
        a[*p]=1;
        while (*++p)
         if (a[*p]==-1)
        {
            a[*p]=digit;
            digit=digit?digit+1:2;
            N++;
        }
        if(N<2) N=2;
        p=s;
        while(*p)
        {
            all=all*N+a[*p++];
        }
        return all;
}
