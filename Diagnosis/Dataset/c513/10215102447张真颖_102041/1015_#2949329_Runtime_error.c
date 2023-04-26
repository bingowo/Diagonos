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
        for(;r.cnt<y.cnt;r.cnt++)
        {
            if(r.cnt<x.cnt)
            {
                int tmp=x.v[r.cnt]+y.v[r.cnt]+carry;
                r.v[r.cnt]=tmp%prime[r.cnt];
                carry=tmp/prime[r.cnt];
            }
            else
            {
                int tmp=y.v[r.cnt]+carry;
                r.v[r.cnt]=tmp%prime[r.cnt];
                carry=tmp/prime[r.cnt];
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
                r.v[r.cnt]=tmp%prime[r.cnt];
                carry=tmp/prime[r.cnt];
            }
            else
            {
                int tmp=x.v[r.cnt]+carry;
                r.v[r.cnt]=tmp%prime[r.cnt];
                carry=tmp/prime[r.cnt];
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
        char sa[26]={0},sb[26]={0};
        scanf("%s%s",sa,sb);
        a.cnt=(strlen(sa)+1)/2;
        b.cnt=(strlen(sb)+1)/2;
        int tmp=0;
        for(int i=0,j=a.cnt-1;i<strlen(sa);i++)
        {
            if(sa[i]>='0'&&sa[i]<='9') tmp=tmp*10+sa[i]-'0';
            else if(sa[i]==',')
                a.v[j]=tmp,tmp=0,j--;
        }
        a.v[0]=tmp;
        tmp=0;
        for(int i=0,j=b.cnt-1;i<strlen(sb);i++)
        {
            if(sb[i]>='0'&&sb[i]<='9') tmp=tmp*10+sb[i]-'0';
            else if(sb[i]==',')
                b.v[j]=tmp,tmp=0,j--;
        }
        b.v[0]=tmp;
        r=add(a,b);
        printf("case #%d:\n",i);
        for(int i=r.cnt-1;i>=0;i--)
            printf("%d%c",r.v[i],i==0?'\n':',');
    }
    return 0;
}