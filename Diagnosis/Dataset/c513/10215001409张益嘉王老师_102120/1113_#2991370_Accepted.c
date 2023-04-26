#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int shu[100];
    int wei;
}bigint;

bigint jia(bigint a,bigint b)
{
    int i,jin=0,mid;
    bigint re;
    memset(re.shu,0,sizeof(int)*100);
    for(i=0;(i<a.wei)||(i<b.wei)||(jin!=0);i++)
    {
        mid=a.shu[i]+b.shu[i]+jin;
        re.shu[i]=mid%10;
        jin=mid/10;
    }
    re.wei=i;
    return re;
}

bigint reverse(bigint a)
{
    int i,mid;
    for(i=0;i<a.wei/2;i++)
    {
        mid=a.shu[i];
        a.shu[i]=a.shu[a.wei-1-i];
        a.shu[a.wei-1-i]=mid;
    }
    return a;
}

int main()
{
    int k,n,i,j;
    bigint lie[110],sum;
    for(i=0;i<110;i++)
    {
        memset(lie[i].shu,0,sizeof(int)*100);
    }
    lie[0].shu[0]=0;
    lie[1].shu[0]=1;
    lie[0].wei=1;
    lie[1].wei=1;
    scanf("%d%d",&k,&n);

    for(i=2;i<n;i++)
    {
        memset(sum.shu,0,sizeof(int)*100);
        sum.wei=1;
        for(j=0;j<k;j++)
        {
            if(i-1-j>=0) sum=jia(lie[i-1-j],sum);
        }
        lie[i]=sum;
    }
    lie[n-1]=reverse(lie[n-1]);

    for(i=0;i<lie[n-1].wei;i++) printf("%d",lie[n-1].shu[i]);
    return 0;
}
