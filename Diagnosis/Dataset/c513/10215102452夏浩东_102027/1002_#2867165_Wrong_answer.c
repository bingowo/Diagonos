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
        int digit=0,N=1,k;
        char *p=s;
        a[*p]=1;
        while(*++p)
        {
            if(a[*p]==-1)
            {
                a[*p]=digit;
                digit = digit? digit+1:2;
                N++;
            }
        }
        if(N<2) N=2;
        long long result=0;
        p=s;
        while(*p){
            result=result*N+a[*p++];
        }
        printf("case #%d\n",i);
        printf("%lld",result);
    }
    return 0;

}