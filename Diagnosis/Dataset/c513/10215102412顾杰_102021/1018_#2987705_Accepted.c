#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{int cnt,v[334];}BIGINT;
BIGINT int2BIG(int x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    }
    while(x>0);
    return R;
}
BIGINT ADD(BIGINT S,BIGINT T)
{
    BIGINT R={0};
    int i,carry=0;
    for(i=0;i<S.cnt&&i<T.cnt;i++)
    {
        int temp=(S.v[i]+T.v[i]+carry);
        R.v[i]=temp%10;
        carry=temp/10;
    }
    while(i<S.cnt)
    {
        int temp=S.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    while(i<T.cnt)
    {
        int temp=T.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    if(carry)
    {
        R.v[i++]=carry%10;
    }
    R.cnt=i;
    return R;
}
BIGINT mul(BIGINT S,BIGINT T)
{
    BIGINT R={S.cnt+T.cnt,{0}};
    for(int i=0;i<T.cnt;i++)
    {
        int t,k,j,carry=0;
        for(j=0;j<S.cnt;j++)
        {
            t=S.v[j]*T.v[i]+carry+R.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while(carry>0)
        {
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if(R.v[S.cnt+T.cnt-1]==0)R.cnt--;
    return R;
}
void DIV2(BIGINT *n)
{
    int carry=0,i;
    if(n->v[n->cnt-1]<2){n->cnt--;carry=1;}
    for(i=n->cnt-1;i>=0;i--)
    {
        int t=10*carry+n->v[i];
        n->v[i]=t/2;
        carry=t%2;
    }
}
long long N2T(long long a)
{
    return a<9?a:N2T(a/10)*9+a%10;
}
int main()
{
     int prime[27]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
     char s[100],*p=s;scanf("%s",s);
     int n=0,i,t;
     BIGINT ans={0,{0}};
     for(;*p;p++)if(*p==',')n++;
     //printf("%d!\n",n);
     p=s;
     while(n>=0)
     {
         t=atoi(p);
         ans=ADD(ans,int2BIG(t));
         ans=mul(ans,int2BIG(prime[n--]));//printf("%s\n",p);
         while(*p!=','&&*p){p++;}
         p++;
     }
     for(i=ans.cnt-1;i>=0;i--)
     printf("%d",ans.v[i]);
}
