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
long long f(int x,int y)
{
    if(x==y)return 1;
    if(x<y)return 0;
    long long a=1;
    for(int i=0;i<x-y-1;i++)a*=2;
    //printf("!!%lld\n",a);
    return 2*f(x-1,y)+a-f(x-y-1,y);
}
int main()
{
    int x,y;
    while(1){
    scanf("%d%d",&x,&y);
    if(x==-1&&y==-1)break;
    printf("%lld\n",f(x,y));}
}
