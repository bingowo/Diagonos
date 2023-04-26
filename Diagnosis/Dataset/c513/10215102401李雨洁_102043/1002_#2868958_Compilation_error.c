#include<stdio.h>
long long A(char *s,long long *ans)
{
    int a[128];
    for (int i=0;i<128;i++) a[i]=-1;
    int digit=0,N=1,i;
    char *p=s;
    a[*p]=1;
    while (*++p) if (a[*p]==-1)   { a[*p]=digit; digit=digit?digit+1:2; N++;}
    if (N<2) N=2;
    p=s;
    long long *ans=0;
    while (*p) ans=ans*N+a[*p++];
    return ans;
}
int main()
{
    int t;//t为测试数据的组数
    char s[60],*ps;
    long long *ans=0;
    for(int i=0;i<t;i++)
    {
        scanf("%s",s);
        ps = s;
        A(ps,ans);
        printf("case #0:\n%lld\n",ans);
    }
    return 0;
}
