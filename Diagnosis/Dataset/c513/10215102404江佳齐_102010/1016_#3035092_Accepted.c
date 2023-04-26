#include<stdio.h>
#include<string.h>

void solve(int n,int m)
{
    if(n==0)return;
    int a=n%m;
    if(a<0)
    {
        a=a-m;
        solve(n/m+1,m);
    }
    else solve(n/m,m);
    if(a>=10)
        a='A'+a-10;
    else
        a=a+'0';
    printf("%c",a);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(n==0) printf("0");
    else solve(n,m);
    return 0;
}
