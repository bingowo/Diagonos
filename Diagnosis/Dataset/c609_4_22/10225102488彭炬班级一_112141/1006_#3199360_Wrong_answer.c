#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[100];
        scanf("%s",s);
        int a[128];
        for(int j;j<128;j++)
            a[j]=-1;
        char *p=s;
        a[*p]=1;
        int r=0;
        while(*++p)
            if(a[*p]==-1)
            {
                a[*p]=r;
                r=r?r+1:2;
            }
        if(r<2)
            r=2;
        long long int n;
        p=s;
        while(*p)
            n=n*r+a[*p++];
        printf("case #%d:\n%lld\n",i,n);
    }
    return 0;
}