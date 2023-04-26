#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct
{
    int cnt;
    int v[N];
}BIGINT;

BIGINT add(BIGINT x,BIGINT y)
{
    BIGINT r;
    r.cnt=0;
    int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int carry=0;
    if(x.cnt<y.cnt)
    {
        for(int i=x.cnt-1,j=y.cnt-1;r.cnt<y.cnt;r.cnt++)
        {
            if(r.cnt<x.cnt)
            {
                int tmp=x.v[i]+y.v[j]+carry;
                r.v[r.cnt]=tmp%prime[r.cnt];
                carry=tmp/prime[r.cnt];
                i--;
                j--;
            }
            else
            {
                int tmp=y.v[j]+carry;
                r.v[r.cnt]=tmp%prime[r.cnt];
                carry=tmp/prime[r.cnt];
                j--;
            }
        }
        if(carry) r.v[r.cnt]=carry,r.cnt++;
    }
    else
    {
        for(int i=x.cnt-1,j=y.cnt-1;r.cnt<x.cnt;r.cnt++)
        {
            if(r.cnt<y.cnt)
            {
                int tmp=x.v[i]+y.v[j]+carry;
                r.v[r.cnt]=tmp%prime[r.cnt];
                carry=tmp/prime[r.cnt];
                i--;
                j--;
            }
            else
            {
                int tmp=x.v[i]+carry;
                r.v[r.cnt]=tmp%prime[r.cnt];
                carry=tmp/prime[r.cnt];
                i--;
            }
        }
        if(carry) r.v[r.cnt]=carry,r.cnt++;
    }
    return r;
}



int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        BIGINT a,b,r;
        int d=0;
        char ch;
        a.cnt=0,b.cnt=0;
        do
        {
            scanf("%d%c",&d,&ch);
            a.v[a.cnt]=d;
            a.cnt++;
        }while(ch==',');
        do
        {
            scanf("%d%c",&d,&ch);
            b.v[b.cnt]=d;
            b.cnt++;
        }while(ch==',');
        r=add(a,b);
        printf("case #%d:\n",i);
        for(int i=r.cnt-1;i>=0;i--)
            printf("%d%c",r.v[i],i==0?'\n':',');
    }
    return 0;
}