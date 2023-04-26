#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cnt,v[100];
} BIGINT;

BIGINT int2BIG(int x)//int转BIGINT
{
    BIGINT r= {0,{0}};
    while(x>0)
    {
        r.v[r.cnt++]=x%10;
        x/=10;
    }
    return r;
}

BIGINT add(BIGINT S, BIGINT T)
{

}

BIGINT pow(int n)
{
    BIGINT r;
    if(n==0) return int2BIG(0);
    if(n==1||n==2) return int2BIG(1);
    else return add(pow(n-1),pow(n-2));
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int n;
        scanf("%d",&n);
        BIGINT ans={0,{0}};
        ans=pow(n);
        printf("case #%d:\n",i);
        for(int j=ans.cnt-1;j>=0;j--)
        {
            printf("%d",ans.v[j]);
        }
        printf("\n");
    }
    return 0;
}



