#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int j;
    for(j=0;j<T;j++)
    {
        printf("case #%d:\n",j);

        char string[61];
        scanf("%s",string);
        int a[128];
        for(int i=0;i<128;i++)
        {
            a[i]=-1;
        }
        int digit=0,N=1,i;
        char *p=string;
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
        if(N<2){N=2;}
        long long ans=0;
        p=string;
        while(*p)
        {
            ans=ans*N+a[*p++];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
