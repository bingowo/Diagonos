#include <stdio.h>
#include <stdlib.h>

int getnum(char c)
{
    int cnt = 0;
    for (int i=0;i<8;i++)
    {
        if (c&1==1) cnt++;
        c >>= 1;
    }
    return cnt;
}

int GCD(int m,int n)
{
    if (m<n) {m^=n; n^=m; m^=n;}
    if (m%n==0) return n;
    else return GCD(n,m%n);
}

main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        char c=0;
        int a=0,b=0;
        while (scanf("%c",&c)!='\n')
        {
            a += getnum(c);
            b++;
        }
        int gcd = GCD(a,b*8);
        printf("%d/%d\n",a/gcd,b*8/gcd);
        a=0,b=0;
    }
    system("pause");
    return 0;
}