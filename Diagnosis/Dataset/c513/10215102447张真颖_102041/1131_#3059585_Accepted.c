#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int d1[20],d2[20];
    int cnt1,cnt2;
    int sign;
}BIGINT;

int main()
{
    int fenzi=0,fenmu=0;
    scanf("%d%d",&fenzi,&fenmu);

    BIGINT d={{0},{0},0,0,1};
    if(fenzi<0) d.sign=-1,fenzi*=-1;
    int tmp=fenzi/fenmu;
    do
    {
        d.d1[d.cnt1++]=tmp%3;
        tmp/=3;
    }while(tmp>0);

    tmp=fenzi%fenmu;
    do
    {
        d.d2[d.cnt2++]=tmp*3/fenmu;
        tmp=(tmp*3)%fenmu;
    }while(tmp>0);

    int carry=0;
    for(int i=d.cnt2-1;i>=0;i--)
    {
        int t=carry+1+d.d2[i];
        d.d2[i]=t%3-1;
        if(d.d2[i]<0) d.d2[i]=2;
        carry=t/3;
    }
    for(int i=0;i<d.cnt1;i++)
    {
        int t=carry+1+d.d1[i];
        d.d1[i]=t%3-1;
        if(d.d1[i]<0) d.d1[i]=2;
        carry=t/3;
    }
    if(carry) d.d1[d.cnt1++]=carry;

    while(d.d1[d.cnt1-1]==0&&d.cnt1>1) d.cnt1--;
    while(d.d2[d.cnt2-1]==0) d.cnt2--;
    if(d.sign<0)
    {
        for(int i=0;i<d.cnt1;i++)
            d.d1[i]=(3-d.d1[i])%3;
        for(int i=0;i<d.cnt2;i++)
            d.d2[i]=(3-d.d2[i])%3;
    }
    for(int i=d.cnt1-1;i>=0;i--)
        printf("%d",d.d1[i]);
    if(d.cnt2>0)
    {
        printf(".");
        for(int i=0;i<d.cnt2;i++)
           printf("%d",d.d2[i]);
    }
    return 0;
}