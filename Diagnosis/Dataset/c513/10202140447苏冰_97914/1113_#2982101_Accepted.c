#include <stdio.h>
#include <string.h>
typedef struct{int cnt,v[100];}BIGINT;
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
BIGINT a[120];
int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    for(int i=0;i<=9;i++)
    {
        a[i].cnt=1;
    }
    a[9].v[0]=1;
    for(int i=1;i<100;i++) a[9].v[i]=0;
    for(int i=10;i<n+8;i++)
    {
        for(int j=i-1;j>=i-k;j--)
        {

            a[i]=ADD(a[i],a[j]);
        }
    }
    for(int i=a[n+7].cnt-1;i>=0;i--)  printf("%d",a[n+7].v[i]);
    return 0;
}
