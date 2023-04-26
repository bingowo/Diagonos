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
long long N2T(long long a)
{
    return a<9?a:N2T(a/10)*9+a%10;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int k,m=0;
        printf("case #%d:\n",i);
        for(int j=8;j>1;j--)
        {
            scanf("%d",&k);
            if(k!=0){if(k>0&&j!=8-m)printf("+");
                    if(k==-1)printf("-");
                    else if(k!=1)printf("%d",k);
                    printf("x^%d",j);}
            else m++;
        }
        scanf("%d",&k);
        if(k!=0){if(k>0&&m!=7)printf("+");
                if(k==-1)printf("-");
                else if(k!=1)printf("%d",k);
                    printf("x");}
        else m++;
        scanf("%d",&k);
        if(k!=0){if(k>0&&m!=8)printf("+");
                printf("%d",k);}
        else m++;
        if(m==9)printf("0");
        printf("\n");
    }
}
