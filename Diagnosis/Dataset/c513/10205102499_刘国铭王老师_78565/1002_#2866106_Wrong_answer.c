#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    char s[61];
    for(int i=0;i<T;i++)
    {
        scanf("%s",s);
        int a[128];
        int res=0;
        for(int j=0;j<128;j++)
            a[j]=-1;
        int digit=0,N=1;
        char *p=s;
        a[*p]=1;
        while(*++p)
            if(a[*p]==-1)
        {
            a[*p]=digit;
            digit=digit?digit+1 : 2;
            N++;
        }
        if(N<2) N=2;
        p=s;
        while(*p)
            res=res*N+a[*p++];
        printf("case #%d:\n",i);
        printf("%d",res);

    }
    return 0;
}
