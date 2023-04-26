#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cnt;
    int v[50];
}BIGINT;
void add(BIGINT* a,BIGINT* b)
{
    int carry=0,i=0;
    for(;i<a->cnt&&i<b->cnt;i++)
    {
        int t=a->v[i]+carry+b->v[i];
        a->v[i]=t%10;
        carry=t/10;
    }
    while(i<a->cnt)
    {
        int t=a->v[i]+carry;
        a->v[i]=t%10;
        carry=t/10;
        i++;
    }
    while(i<b->cnt)
    {
        int t=b->v[i]+carry;
        a->v[i]=t%10;
        carry=t/10;
        i++;
        a->cnt++;
    }
    if(carry)
        a->v[i]=carry,a->cnt++;
}

int main()
{
    int k=0,n=0;
    scanf("%d%d",&k,&n);
    BIGINT arr[100]={0};
    arr[0].cnt=1,arr[0].v[0]=0;
    arr[1].cnt=1,arr[1].v[0]=1;
    for(int i=2;i<n;i++)
    {
        for(int t=1;t<=k;t++)
        {
            if(i-t>=0) add(&arr[i],&arr[i-t]);
        }
    }
    for(int i=arr[n-1].cnt-1;i>=0;i--)
        printf("%d",arr[n-1].v[i]);
    return 0;
}
