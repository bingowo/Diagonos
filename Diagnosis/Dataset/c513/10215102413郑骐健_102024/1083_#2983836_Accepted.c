#include <stdio.h>
#include <stdlib.h>
#define width 1500

typedef struct {
int a[3000];
int cnt;
}bigint;

bigint trans(int a)
{
    bigint mid;
    memset(mid.a,0,sizeof(mid.a));
    mid.cnt =0;
    do
    {
        mid.a[mid.cnt++]=a%10;
        a/=10;
    }while(a!=0);
    return mid;
}

bigint mul(bigint a,bigint b)
{
    bigint mid;
    memset(mid.a,0,sizeof(mid.a));
    mid.cnt =a.cnt+b.cnt;
    int i,k;
    for( i =0;i<a.cnt;i++)
    {
        int  carry=0;
        for( k=0;k<b.cnt;k++)
        {
            int p;
            p=a.a[i]*b.a[k]+mid.a[i+k]+carry;
            carry=p/10;
            mid.a[i+k]=p%10;
        }
        int g=i+k;
        while(carry>0)
        {
            int p=mid.a[g]+carry;
            carry = p/10;
            mid.a[g]=p%10;
            g++;
        }
    }
    if(mid.a[mid.cnt-1]==0)mid.cnt--;
    return mid;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        bigint mid;
        bigint res = trans(1);
        for(int q=2;q<=t;q++)
        {
            mid = trans(q);
            res = mul(res,mid);
        }
        int con=0;
        for(int g=0;g<res.cnt;g++)
        {
            if(res.a[g]!=0)break;
            else con++;
        }
        printf("case #%d:\n",i);
        printf("%d\n",con);
    }

    return 0;
}
