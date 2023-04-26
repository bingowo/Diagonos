#include<stdio.h>
#include<string.h>

int ones(unsigned char d) /*计算1的位数*/
{
    int r;
    for(r=0;d>0;d>>=1)
    {
        if(d&1)
        {
            r++;
        }
    }
    return r;
}

int GCD(int a,int b)/*求1所占位数和总位数的最大公约数*/
{
    return a%b?GCD(b,a%b):b;


}

void solve()
{
    char s[122];
    int i,cnt1,cnt10,gcd;
    fgets(s,sizeof s,stdin);
    for(cnt10 = cnt1 = i = 0;s[i] != '\n';i++)
    {
        cnt1+=ones(s[i]);
        cnt10+=8;
    }
    gcd=GCD(cnt1,cnt10);
    printf("%d/%d\n",cnt1/gcd,cnt10/gcd);
}
int main()
{
    int n;
    char a;
    scanf("%d",&n);
    while(scanf("%c",&a) != EOF)
    {
        solve();
    }
    return 0;
}
