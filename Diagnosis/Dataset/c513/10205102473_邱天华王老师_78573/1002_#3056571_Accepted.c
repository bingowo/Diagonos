#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int m=0;m<t;m++)
{
    char s[61];
    int a[128];
    long long ans=0;
    int digit=0,N=1;   
    char *p=s; 
    for (int i=0;i<128;i++)
         a[i]=-1; 
    scanf("%s",s);
    a[*p]=1;
    while (*++p) 
    if (a[*p]==-1)   
    { 
        a[*p]=digit; 
        digit=digit?digit+1:2; 
        N++;
    }
    if(N<2) 
        N=2;
    p=s; 
    while (*p) ans=ans*N+a[*p++];
    printf("case #%d:\n",m);
    printf("%lld\n",ans);
}
    return 0;
}
