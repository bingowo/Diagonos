#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int m,int n)
{
    return (n?GCD(n,m%n):m);
}
int main()
{
    int n,a=0,d=1,gcd,m=0;
    char c;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        while(c=getchar()!='\n')
        {
            for(int j=0;j<8;j++)
            {
                if(c&d) a++;w
                d=d<<1;
            }
            m+=1;
        }
        gcd=GCD(a,8*m);
        printf("%d/%d\n",a/gcd,8*m/gcd);
    }
    return 0;
}
