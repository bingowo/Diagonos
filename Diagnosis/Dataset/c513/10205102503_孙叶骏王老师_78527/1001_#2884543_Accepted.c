#include<stdio.h>
char *s="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void solve()
{
    int n,r;
    scanf("%d%d",&n,&r);
    if(n<0)
    {
        printf("-");
        n=-n;
    }
    int res[35],sz=0;
    do
    {
        res[sz++]=n%r;
    }while(n/=r);
    for(int i=sz-1;~i;--i)
    {
        printf("%c",s[res[i]]);
    }
    printf("\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
}