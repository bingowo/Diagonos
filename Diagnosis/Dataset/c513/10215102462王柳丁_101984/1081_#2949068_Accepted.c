#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct bigint
{
    int cnt;
    int v[100];
}BIGINT;
BIGINT ITB(int a);
BIGINT pow(BIGINT a,int n);
BIGINT mul(BIGINT a,BIGINT b);
int main()
{
   int T,i;
   scanf("%d",&T);
   for(i=0;i<T;i++)
   {
       int a,n;
       scanf("%d %d",&a,&n);
       BIGINT res=ITB(a);
       res=pow(res,n);
       int j;
       printf("case #%d:\n",i);
       for(j=res.cnt-1;j>=0;j--)
       {
           printf("%d",res.v[j]);
       }
       printf("\n");
   }
    return 0;
}

BIGINT ITB(int a)
{
    BIGINT res;
    res.cnt=0;
    while(a>0)
    {
        res.v[res.cnt++]=a%10;
        a=a/10;
    }
    return res;
}
BIGINT pow(BIGINT a,int n)
{
    BIGINT res;
    if(n==0)return ITB(1);
    else if(n==1)return a;
    else
    {
        res=pow(a, n/2);
        res=mul(res,res);
        if(n%2==1)res=mul(res,a);
    }
    return res;
}
BIGINT mul(BIGINT a,BIGINT b)
{
    int add=0,i,j,eve=0;
    BIGINT res={a.cnt+b.cnt,{0}};
    for(i=0;i<a.cnt;i++)
    {
        for(j=0;j<b.cnt;j++)
        {
            eve=a.v[i]*b.v[j]+add+res.v[i+j];
            res.v[i+j]=eve%10;
            add=eve/10;
        }
        int k=i+j;
        while(add>0)
        {
            eve=(res.v[k]+add)%10;
            res.v[k]=eve;
            add/=10;
            k++;
        }
    }
    if (res.v[a.cnt+b.cnt-1]==0)res.cnt--;
    return res;

}
