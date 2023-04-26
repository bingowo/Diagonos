#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    scanf("%d",&i);
    char s[61];
    for(int k=0;k+1<=i;k++)
    {
        printf("case #%d:\n",k);
    scanf("%s",s);
    int a[128];
    for(int j=0;j<128;j++)a[j]=-1;
    int digit=0,N=1;
    char *p=s;
    a[*p]=1;
    while(*++p)
    if(a[*p]==-1)
    {
        a[*p]=digit;
        digit=digit?digit+1:2;
        N++;
    }
    if(N<2)N=2;
    long long ans=0;
    p=s;
    while(*p)
    ans=ans*N+a[*p++];
    printf("%lld\n",ans);
    }
    return 0;
}