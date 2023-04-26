#include <stdio.h>
#include <stdlib.h>

int gcd(int x,int y)
{
    if(y) return gcd(y,x%y);
    else return x;
}

void solve(char s[])
{
    int ans1=0,ans2=1;
    int len=strlen(s);

    int x=gcd(ans1,ans2);
    printf("%d/%d\n",ans1/x,ans2/x);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[125]={0};
        scanf("%s",&s);
        solve(s);
    }

    return 0;
}