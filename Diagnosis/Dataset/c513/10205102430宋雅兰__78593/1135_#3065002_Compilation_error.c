#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define N 1000
typedef struct{
    int cnt;
    int v[N];
}BIGINT;
BIGINT cal(BIGINT a,BIGINT b,BIGINT c)
{
    int i=0,carry=0;
    while(i<a.cnt&&i<c.cnt)
    {
        a.v[i]+=c.v[i]+carry;
        carry=a.v[i]/10;
        a.v[i]%=10;
        i++;
    }
    while(i<a.cnt){
        a.v[i]
    }
    i=0;carry=0;
    for (i=0; i<b.cnt+1; i++)
    {
        int t=b.v[i]*3+carry;
        b.v[i]=t%10;
        carry=t/10;
    }
    return a;
}
int main()
{
    int n;
    scanf("%d",&n);
    BIGINT *ans;
    ans=(BIGINT*)malloc(sizeof(BIGINT)*(n+1));
    ans[1].cnt=1;
    ans[1].v[0]=1;
    ans[2].cnt=1;
    ans[2].v[0]=2;
    ans[3].cnt=1;
    ans[3].v[0]=3;
    ans[4].cnt=1;
    ans[4].v[0]=6;
    for(int i=5;i<=n;i++)
    {
        ans[i]+=ans[i-1];
        ans[i]+=ans[i-2]*3;
        ans[i]+=ans[i-4];
    }
    return 0;
}