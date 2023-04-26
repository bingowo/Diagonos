#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 120

typedef struct
{
    char s[M];
    int shu[M];
    int wei;
}bigint;

bigint reverse(bigint a)
{
    int i,c;
    for(i=0;i<(a.wei/2);i++)
    {
        c=a.shu[i];
        a.shu[i]=a.shu[a.wei-i-1];
        a.shu[a.wei-1-i]=c;
    }
    return a;
}

bigint d9jia1(bigint n,int pl)
{
    int i,jin=1,mid;
    for(i=pl;(i<n.wei)||jin!=0;i++)
    {
        mid=n.shu[i]+jin;
        n.shu[i]=mid%9;
        jin=mid/9;
    }
    n.wei=i;
    return n;
}

bigint find9andadd(bigint n)
{
    int i,j;
    for(i=0;i<n.wei;i++)
    {
        if(n.shu[i]==9)
        {
            for(j=i+1;j<n.wei;j++)
            {
                n.shu[j]=0;
            }
            n=reverse(n);
            n=d9jia1(n,n.wei-1-i);
            break;
        }
    }
    if(i==n.wei)
    {
        n=reverse(n);
        n=d9jia1(n,0);
    }
    return n;
}

int is9bei(bigint n)
{
    int sum=0,i;
    for(i=0;i<n.wei;i++)
    {
        sum+=n.shu[i];
    }
    if(sum%9==0) return 1;
    else return 0;

}

int main()
{
    bigint n;
    int i,len;
    scanf("%s",n.s);
    len=strlen(n.s);
    memset(n.shu,0,sizeof(int)*M);
    for(i=0;i<len;i++)
    {
        n.shu[i]=n.s[i]-'0';
    }
    n.wei=len;
    n=find9andadd(n);
    while(is9bei(n))
    {
        n=d9jia1(n,0);
    }
    n=reverse(n);
    for(i=0;i<n.wei;i++) printf("%d",n.shu[i]);
    return 0;

}
