#include<stdio.h>
int GCD(int m,int n)
{
    int a;
    if(m<n) a=m,m=n,n=a;
    if(m%n!=0) return GCD(n,m%n);
    else return n;
}
int main()
{
    char a;
    unsigned int n,b,c=0,d=0,sum=0,z,x;
    scanf("%u",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%c",&a);
        scanf("%c",&a);
        b=(unsigned int) a;
            c++;
            while(b!=0)
            {
                if((b&1)==1) d++;
                b=b>>1;
            }
            sum=sum+d;
            d=0;
        while(a!='\n')
        {
            scanf("%c",&a);
            b=(unsigned int) a;
            c++;
            while(b!=0)
            {
                if((b&1)==1) d++;
                b=b>>1;
            }
            if(a!='\n') sum=sum+d;
            d=0;
        }
        z=8*c-8;
        x=GCD(z,sum);
        printf("%d/%d\n",sum/x,z/x);
        sum=0;
        c=0;
    }
    return 0;
}