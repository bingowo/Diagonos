#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 60

int main()
{
    int T;
    scanf("%d",&T);
    for (int m=0;m<T;m++)
    {
        printf("case #%d:\n",m);
        char s[61];
        scanf("%s",s);
        int digit=0,N=1,i;
        int a[128]; for (i=0;i<128;i++) a[i]=-1;
        char *p=s;
        a[*p]=1;
        while(*++p)
            if (a[*p]==-1)
                {a[*p]=digit;digit=digit?digit+1:2;N++;}
        if (N<2) N=2;
        long long ans=0;
        p=s;
        while (*p)
            ans=ans*N+a[*p++];
        printf("%lld\n",ans);
    }

    return 0;
}
