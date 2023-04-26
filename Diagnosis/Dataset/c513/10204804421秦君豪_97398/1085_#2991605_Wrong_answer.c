#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define maxn 1000000

typedef long long int lli;

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

void minus(BIGINT a,BIGINT b)//ab相减
{
    int isnegative =0;
    if(a.cnt<b.cnt) isnegative =1;
    else if(a.cnt==b.cnt)
    {
        int i=a.cnt;
        while (a.v[i]==b.v[i])
        {
            i--;
        }
        if (a.v[i]<b.v[i]) isnegative=1;
    }
    if (isnegative==1)
    {
        printf("-");
        minus(b,a);
    }
    else
    {
        for(int j=0;j<a.cnt;j++)
        {
            if(a.v[j]<b.v[j])
            {
                a.v[j+1]--;
                a.v[j]+=10;
            }
            a.v[j]-=b.v[j];
        }
        while(a.v[a.cnt-1]==0) a.cnt--;
//        printf("%d",a.cnt);
        for(int j=a.cnt-1;j>=0;j--)
            printf("%d",a.v[j]);
        printf("\n");
    }

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



int main(void)
{
    int a,b;
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        BIGINT A=int2BIG(a);
        BIGINT B=int2BIG(b);
        minus (A,B);
    }
    return 0;

}
