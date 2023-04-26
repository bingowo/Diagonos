#include<stdio.h>
int main()
{
    int a;
    long long int ans[a];
    scanf("%d\n",&a);
    char s[a][61];
    for(int i=0;i<a;i++)
    {
        scanf("%s",s[i]);
        int b[128];
        for(int j=0;j<128;j++)
        {
            b[j]=-1;
        }
        int digit=0,N=1,k;char *p=s[i];
        b[*p]=1;
        while(*++p)
        {
            if(b[*p]==-1)
            {
                b[*p]=digit;
                digit=digit?digit+1:2;
                N++;
            }
        }
        if(N<2)
        {
            N=2;
        }
        p=s[i];
        while(*p)
        {
            ans[i]=ans[i]*N+b[*p++];
        }
    }
    for(int i=0;i<a;i++)
    {
        printf("case #%d:\n",i);
        printf("%lld",ans[i]);
    }
    return 0;

    
}