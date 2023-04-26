#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,n=0;
    scanf("%d\n",&T);
    for (;n<T;n++)
    {
        char s[62];
        int i=0;
        s[i]=getchar();
        while (s[i] != '\n')
        {
            s[++i]=getchar();
        }
        long long ans=0;
        int len=strlen(s),N=0;
        char *p=s;
        int a[128];
        for (int t=0;t<128;t++) a[t]=-1;
        a[*p]=1;
        while (*++p)
        {
            if (a[*p] == -1)
            {
                a[*p]=N;
                N=N ? N+1 : 2;
            }
        }
        if (N<2) N=2;
        p=s;
        while (*p)
            ans=ans*N+a[*p++];
        printf("case #%d:\n",n);
        printf("%lld\n",ans);
    }
    return 0;
}
