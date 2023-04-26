#include<stdio.h>
typedef struct 
{
    int l;
    int v[120];
}bigint;
bigint int2big(int x)
{
    bigint rt={0,{0}};
    while(x>0)
    {
        rt.v[rt.l++]=x%10;
        x=x/10;
    }
    return rt;
}
bigint mul(bigint a,bigint b)
{
    bigint rt={0,{0}};
    int i,j,k,t,carry;
    for(i=0;i<b.l;i++)
    {
        for(j=0;j<a.l;j++)
        {
            t=a.v[j]*b.v[i]+carry+rt.v[i+j];
            rt.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while(carry!=0)
        {
            t=rt.v[k]+carry;
            rt.v[k]=t%10;
            carry=t/10;
            k++;
        }
        if(k>rt.l)  rt.l=k;
    }
    return rt;
}
bigint pow(bigint a,int n)
{
    bigint rt;
    if(n==0)  return int2big(1);
    if(n==1)  return a;
    rt=pow(a,n/2);
    rt=mul(rt,rt);
    if(n%2==1)  rt=mul(rt,a);
    return rt;
}
int main()
{
    int T,i,j,a,n;
    bigint x,y,ans;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d%d",&a,&n);
        x=int2big(a);
        ans=pow(x,n);
        printf("case #%d:\n",i);
        for(j=ans.l-1;j>=0;j--)  printf("%d",ans.v[j]);
        printf("\n");
    }
    return 0;
}