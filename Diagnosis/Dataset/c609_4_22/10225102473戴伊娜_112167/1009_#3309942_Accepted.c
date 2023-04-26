#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

void solve()
{
    char s[122];
    int i,cnt,m,g,length;
    cnt=m=0;
    fgets(s,122,stdin);
    length=strlen(s)-1;
    m=8*length;
    for(i=0;i<length;i++)
    {
        unsigned char c=s[i];
        while(c>0)
        {
            if(c&1)
                cnt++;
            c>>=1;
        }
    }
    g=gcd(m,cnt);
    printf("%d/%d\n",cnt/g,m/g);
}

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        solve();
    }
    return 0;
}
