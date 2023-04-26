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
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void* b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    int *a,sum=0,n,w[11];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        sum=sum+w[i];
    }
    a=(int*)malloc((sum+1)*sizeof(int));
    for(int i=1;i<=sum;i++)
        a[i]=0;
    qsort(w,n,sizeof(a[0]),cmp);
    for(int i=0;i<n;i++)
    {
        a[w[i]]=1;
        for(int j=1;j<=sum;j++)
        {
            if(a[j]==1 && j!=w[i])
            {
                if(j-w[i]>0)
                    a[j-w[i]]=1;
                if(j+w[i]<=sum)
                    a[j+w[i]]=1;
            }
        }

    }
    for(int i=1;i<=sum;i++)
        printf("%d ",a[i]);
    return 0;
}
*/