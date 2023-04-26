#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cnt;
    int v[100];
}BIGINT;

BIGINT i2b(int x)
{
    BIGINT bigx;
    bigx.cnt=0;
    while(x)
    {
        bigx.v[bigx.cnt]=x%10;
        bigx.cnt++;
        x/=10;
    }
    return bigx;
}
BIGINT add(BIGINT x,BIGINT y)
{
    BIGINT r;
    r.cnt=0;
    int carry=0;
    if(x.cnt<y.cnt)
    {
        for(;r.cnt<y.cnt;r.cnt++)
        {
            if(r.cnt<x.cnt)
            {
                int tmp=x.v[r.cnt]+y.v[r.cnt]+carry;
                r.v[r.cnt]=tmp%10;
                carry=tmp/10;
            }
            else
            {
                int tmp=y.v[r.cnt]+carry;
                r.v[r.cnt]=tmp%10;
                carry=tmp/10;
            }
        }
        if(carry) r.v[r.cnt]=carry,r.cnt++;
    }
    else
    {
        for(;r.cnt<x.cnt;r.cnt++)
        {
            if(r.cnt<y.cnt)
            {
                int tmp=x.v[r.cnt]+y.v[r.cnt]+carry;
                r.v[r.cnt]=tmp%10;
                carry=tmp/10;
            }
            else
            {
                int tmp=x.v[r.cnt]+carry;
                r.v[r.cnt]=tmp%10;
                carry=tmp/10;
            }
        }
        if(carry) r.v[r.cnt]=carry,r.cnt++;
    }
    return r;
}
BIGINT mul(BIGINT x,int b)
{
    BIGINT r;
    r.cnt=0;
    int carry=0;
    for(;r.cnt<x.cnt;r.cnt++)
    {
        int tmp=x.v[r.cnt]*b+carry;
        r.v[r.cnt]=tmp%10;
        carry=tmp/10;
    }
    if(carry) r.v[r.cnt]=carry,r.cnt++;
    return r;
}

int main()
{
    int a[25]={0},d=0,cnt=0;
    int prime[]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    char ch;
    do
    {
        scanf("%d%c",&d,&ch);
        a[cnt]=d;
        cnt++;
    }while(ch==',');
    BIGINT biga;
    biga.cnt=0,biga.v[0]=0;
    for(int i=0;i<cnt;i++)
    {
         biga=add(biga,i2b(a[i]));
         biga=mul(biga,prime[cnt-i-1]);
    }
    for(int i=biga.cnt-1;i>=0;i--)
        printf("%d",biga.v[i]);
    if(biga.cnt==0) printf("0");
    return 0;
}