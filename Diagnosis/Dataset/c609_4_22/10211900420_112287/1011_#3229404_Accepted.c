#include<stdio.h>
#include<string.h>
long long pow(long long x,long long y)
{
    long long z;
    z=1;
    long long i;
    for(i=0;i<y;i++)
    {
        z=z*x;
    }
    return z;
}
int main()
{
    char a[100],b[100] = {0},c[100] = {0};
    long long sum,sign,zi,mu;
    zi=0;
    sum=0;
    long long j=0,i,m,len;
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        if(a[i]!='.')
        {
            b[i]=a[i];

        }
        else
        {
            break;
        }
    }
    for(m=0;m<strlen(b);m++)
    {
        if(b[m]=='1')
        {
            sum=sum+pow(3,strlen(b)-m-1);

        }
        else if(b[m]=='2')
        {
            sum=sum-pow(3,strlen(b)-m-1);
        }
    }
    if(strlen(b)!=len)
    {
        for(i=i+1;i<len;i++)
        {
            c[j]=a[i];

            j++;
        }
        mu=pow(3,strlen(c));
        for(m=0;m<j;m++)
        {
            if(c[m]=='1')
                zi=zi+pow(3,strlen(c)-m-1);
            else if(c[m]=='2')
                zi=zi-pow(3,strlen(c)-m-1);
        }
        if(sum*zi>0)
        {
            if(zi<0)
                zi=-zi;
            printf("%lld %lld %lld",sum,zi,mu);
        }
        else if(sum<0 && zi>=0)
        {
            sum++;
            zi=mu-zi;
            printf("%lld %lld %lld",sum,zi,mu);
        }
        else if(sum>0 && zi<=0)
        {
            sum--;
            zi=mu+zi;
            printf("%lld %lld %lld",sum,zi,mu);
        }
        else
        {
            printf("%lld %lld",zi ,mu);
        }
    }
    else
        printf("%lld",sum);
    return 0;
}
