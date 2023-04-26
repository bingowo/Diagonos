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
int main()
{
    int i,a[21],x;
    a[1]=2;a[2]=3;a[3]=7;
    for(i=4;i<=20;i++)
    {
        a[i]=2*a[i-1];
        int f=-1;
        for(int j=i-3;j>=1;j-=2)
        {
            a[i]+=f*a[j];
            f*=-1;
        }
    }
    while(1){
    scanf("%d",&x);
    if(x==-1)break;
    if(x==2)printf("4\n");
    else printf("%d\n",a[x]);
    }
}
