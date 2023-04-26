#include<stdio.h>
#include<stdlib.h>
long long gcd(long long x,long long y)
{
    if(y!=0)
        return gcd(y,x%y);
    else 
        return x;
}
long long jcs(long long m, long long n)
{
    long long temp,g,res,fz,fm,t;
    int i;
    if(n==1)
        return m;
    else 
    {
        fz=1;
        fm=1;
        t=n;
        for(i=0;i<t;i++)
        {
            fm=fm*n;
            fz=fz*m;
            g=gcd(fz,fm);
            if(g!=1)
            {
                fz=fz/g;
                fm=fm/g;
            }
            n--;
            m--;
        }
        res=fz/fm;
        return res;
    }
        
}
int main()
{
    int T;
    int i;
    long long m,n,t;
    long long res=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        res=0;
        scanf("%lld%lld",&m,&n);
        t=m-n;
        if(t<n)
            n=t;
        printf("case #%d:\n",i);
        if(n==0)
            printf("1\n");
        else if(n==1)
            printf("%lld\n",m);
        else
        {
            res=jcs(m,n);
            printf("%lld\n",res);
        }
    }
    return 0;
}