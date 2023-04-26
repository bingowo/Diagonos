#define _CRT_SECURE_NO_WARNINGS 1
/* strchr example */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

typedef struct
{
    int s[200];
    int cnt;
}bigint;

bigint trans(int a)
{
    bigint mid;
    memset(&mid,0,sizeof(bigint));
    do
    {
        mid.s[mid.cnt++]=a%10;
        a/=10;
    }while(a!=0);
    return mid;
}

bigint add(bigint a,bigint b)
{
    bigint res;
    memset(&res,0,sizeof(bigint));
    int carry =0;
    int i;
    for( i=0;i<a.cnt||i<b.cnt;i++)
    {
        int p =a.s[i]+b.s[i]+carry;
        res.s[i] = p%10;
        carry=p/10;
    }
    if(carry>0)
    {
        res.s[i]=1;
        res.cnt=i+1;
    }
    else res.cnt =i;
    return res;

}
void copy(bigint*p1,bigint p2)
{
    memset(p1,0,sizeof(bigint));
    for(int i=0;i<p2.cnt;i++)
    {
        p1->s[i]=p2.s[i];
    }
    p1->cnt=p2.cnt;
}
int main()
{
   int k,n;
   scanf("%d%d",&k,&n);
   bigint*p=(bigint*)malloc(sizeof(bigint)*200);
   int o[11] ={0,1,1,2,4,8,16,32,64,128,256};
   for(int i =0;i<k;i++)
    {
        copy(&p[i],trans(o[i]));
    }
   for(int g=k;g<n;g++)
   {
       bigint res;
       memset(&res,0,sizeof(res));
       for(int h=g-k;h<g;h++)
       {
           res = add(res,p[h]);
       }
       copy(p+g,res);
   }
   for(int q=p[n-1].cnt-1;q>=0;q--)
   {
       printf("%d",p[n-1].s[q]);
   }
   return 0;
}
