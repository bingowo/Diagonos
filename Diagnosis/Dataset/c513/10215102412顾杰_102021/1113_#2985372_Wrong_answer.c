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
unsigned long long minu(char*b,char*a,int x)
{
    char*pb=b+strlen(b),*pa=a+strlen(a);
    int carry=0,lb=strlen(b);
    unsigned long long ans=0;
    while(pa>=a)
    {
        *pb-=*pa;
        if(*pb<0){*pb+=x;*(pb-1)-=1;}
        pa--;pb--;
    }
    while(pb>=b)
        {
            if(*pb<0){*pb+=x;*(pb-1)-=1;}
            if(*pb>='0')*pb-='0';
            pb--;
        }
    for(int i=0;i<lb;i++)
    {
        ans*=x;
        ans+=b[i];
    }
    return ans;
}
int main()
{
    long long a[121];
    int i,n,k;
    for(i=0;i<=11;i++)a[i]=0;
    a[i]=1;
    scanf("%d%d",&k,&n);
    for(i++;i<=n+10;i++)
    {
        for(int j=i-k;j<i;j++)a[i]+=a[j];
    }
    printf("%lld",a[n+10]);
}
