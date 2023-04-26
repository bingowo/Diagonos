#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int GCD(int m,int n)
{
    int mn,i;
    if(m>n)
    {
        mn=m;
        m=n;
        n=mn;
    }
    for(i=2;i<=n;i++)
    {
        if((m%i==0) &&(n%i==0))
        {
            m=m/i;
            n=n/i;
            return i*GCD(m,n);
        }
    }
    return 1;
}
int main()
{
    char a[200];
    int y,gcd,sum1,sum2,x,len,n,i,j,k;
    scanf("%d",&n);
    gets(a);
    for(i=0;i<n;i++)
    {
        sum1=0;
        sum2=0;
        gets(a);
        len=strlen(a);
        for(j=0;j<len;j++)
        {
            x=(int)a[j];
            for(k=0;k<8;k++)
            {
                y=x&1;
                sum1=sum1+y;
                x=x>>1;
            }
            sum2=sum2+8;
        }
        gcd=GCD(sum1,sum2);
        sum1=sum1/gcd;
        sum2=sum2/gcd;
        printf("%d/%d\n",sum1,sum2);
    }
    return 0;
}