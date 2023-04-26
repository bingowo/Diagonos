#include <stdio.h>
#include <stdlib.h>
int a[10000][10000];
long long  min(long long m,long long  n)
{
    if(n>m)return m;
    else return n;
}
long long  youxia(long long m,long long n,long long k)
{
    long long i=0,j=0,g=0,count=0,p=0,q=0,x,y;
    long long sum=0;
    for(i=2;i<=min(m,n);i++)
    {
        j=(n+1-i)*(m+1-i);
        for(g=0;g<j;g++)
        {
            sum=0;
            x=g/(m-1);
            y=g%(m-1);
           for(p=x;(p-x)<i;p++)
           {
               for(q=y;(p+q-x-y)<i;q++)
                {sum=sum+a[p][q];}
           }

           if(sum>=k)count++;
        }
    }
    return count;
}
long long  zuoxia(long long m,long long n,long long k)
{
    long long  i=0,j=0,g=0,count=0,p=0,q=0,x=0,y=0;
    long long sum=0;
    for(i=2;i<=min(m,n);i++)
    {
        j=(n+1-i)*(m+1-i);
        for(g=0;g<j;g++)
        {
            sum=0;
             x=g/(m-1);
            y=g%(m-1)+i-1;
           for(q=y;(y-q)<i;q--)
           {

               for(p=x;(y+p-q-x)<i;p++)
                sum=sum+a[p][q];
           }
           if(sum>=k)count++;
        }
    }
    return count;
}
long long youshang(long long m,long long n,long long k)
{
    long long i=0,j=0,g=0,count=0,p=0,q=0,x,y;
    long long sum=0;
    for(i=2;i<=min(m,n);i++)
    {
        j=(n+1-i)*(m+1-i);
        for(g=0;g<j;g++)
        {
            sum=0;
            x=g/(m-1)+i-1;
            y=g%(m-1);
           for(p=x;(x-p)<i;p--)
           {
               for(q=y;(q-y+x-p)<i;q++)
                {sum=sum+a[p][q];}
           }
        if(sum>=k)count++;
        }
    }
      return count;
}
long long  zuoshang(long long  m,long long n,long long  k)
{
    long long  i=0,j=0,g=0,count=0,p=0,q=0,x=0,y=0;
    long long sum=0;
    for(i=2;i<=min(m,n);i++)
    {
        j=(n+1-i)*(m+1-i);
        for(g=0;g<j;g++)
        {
            sum=0;
             x=g/(m-1)+i-1;
            y=g%(m-1)+i-1;
           for(q=y;(y-q)<i;q--)
           {

               for(p=x;(y-q+x-p)<i;p--)
                sum=sum+a[p][q];
           }
           if(sum>=k)count++;
        }
    }
    return count;
}
int main()
{
    long long  n,m,k,i,j;
    long long  count;
    scanf("%lld %lld %lld",&n,&m,&k);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    }
    long long  count1=0,count2=0,count3=0,count4=0;
    count1=youxia(m,n,k);
    count2=zuoxia(m,n,k);
    count3=youshang(m,n,k);
    count4=zuoshang(m,n,k);
    count=count1+count2+count3+count4;
    printf("%lld\n",count);

    return 0;
}
