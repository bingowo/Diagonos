#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct{int cnt,v[110];}BIGINT;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
BIGINT int2BIG(int x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    }while(x>0);
    return R;
}
BIGINT ADD(BIGINT S,BIGINT T)
{
    BIGINT R={0};
    int i,carry=0;
    for(i=0;i<S.cnt && i<T.cnt;i++)
    {
        int temp=(S.v[i]+T.v[i]+carry);
        R.v[i]=temp%10;
        carry=temp/10;
    }
    while(i<S.cnt)
    {
        int temp =S.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    while(i<T.cnt)
    {
        int temp =T.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    if(carry) R.v[i++]=carry%10;
    R.cnt=i;
    return R;
}
BIGINT mul(BIGINT S,BIGINT T)
{
    BIGINT R={S.cnt+T.cnt,{0}};
    for(int i=0;i<T.cnt;i++)
    {
        int t,k,j;
        int carry=0;
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
    if(R.v[S.cnt+T.cnt-1]==0) R.cnt--;
    return R;
}
int main()
{
    int a[30]={0};
    int i=0;char c;
    while(1)
    {
        scanf("%d%c",&a[i++],&c);
        if(c=='\n') break;
    }
    BIGINT ANS={0,{0}};
    BIGINT X={0,{0}},M={0,{0}};
    for(int j=i-1;j>=0;j--)
    {
        X=int2BIG(a[j]);
        for(int k=0;k<i-1-j;k++)
        {
            M=int2BIG(prime[k]);
            X=mul(X,M);
        }
        ANS=ADD(ANS,X);
    }
    for(int j=ANS.cnt-1;j>=0;j--) printf("%d",ANS.v[j]);
    return 0;
}


