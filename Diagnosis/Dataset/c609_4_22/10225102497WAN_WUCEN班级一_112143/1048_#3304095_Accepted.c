//斐波那契数列
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cnt,v[100];
}BIGINT;

BIGINT add(BIGINT a,BIGINT b);

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n=0;
        BIGINT sequence={1,{0}},temp1={1,{1}},temp2={1,{0}};
        scanf("%d",&n);
        for(int j=1;j<n;j++)
        {
            sequence=add(temp1,temp2);
            temp2=temp1;
            temp1=sequence;
        }
        printf("case #%d:\n",i);
        for(int j=sequence.cnt-1;j>=0;j--)
            printf("%d",(n==1)?1:sequence.v[j]);
        printf("\n");
    }
    return 0;
}

BIGINT add(BIGINT a,BIGINT b)
{
    BIGINT c={1,{0}};
    int carry=0;
    int cnt=0;
    for(cnt=0;cnt<a.cnt||cnt<b.cnt;cnt++)
    {
        c.v[cnt]=a.v[cnt]+b.v[cnt]+carry;
        carry=c.v[cnt]/10;
        c.v[cnt]%=10;
    }
    if(carry)
    {
        c.v[cnt]=carry;
        c.cnt=cnt+1;
    }
    else
        c.cnt=cnt;
    return c;
}
