#include<stdio.h>

#define N 3000
typedef struct{int cnt,v[N];}BIGINT;

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
BIGINT ans[501]={{1,{1}},{1,{1}},{1,{2}},{1,{3}},{0,{0}}};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=4;i<=n;i++)
    {
        ans[i]=ADD(ADD(ans[i-1],ans[i-2]),ans[i-4]);
    }
    for(int i=ans[n].cnt-1;i>=0;i--)printf("%d",ans[n].v[i]);
    return 0;
}
