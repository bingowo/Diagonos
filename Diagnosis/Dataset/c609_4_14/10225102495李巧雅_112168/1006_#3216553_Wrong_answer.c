#include <stdio.h>
long long seinform(char s[61])
{
    int a[128],i,digit=0,N=1;
    for(i=0;i<128;i++)
    {
        a[i]=-1;
    }
    char *p=s;
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
    if(N<2) N=2;
    p=s;
    long long ans=0;
    while(*p)
    {
        ans=ans*N+a[*p++];
    }
    return ans;
}
int main()
{
    int T,i,j;
    char s[61];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",s);
    }
    for(j=0;j<T;j++)
    {
        printf("case #%d:",j);
        printf("\n");
        printf("%lld\n",seinform(s));
    }
    return 0;
}
