#include <stdio.h>
#include <stdlib.h>
#define LL long long
#define N 100
typedef struct{int cnt, v[N];} BIGINT;

BIGINT int2BIG(LL x)
{
    BIGINT R={0,{0}};
    do{
        R.v[R.cnt++]=x%10;
        x/=10;
    } while (x>0);
    return R;
}
BIGINT ADD(BIGINT S,BIGINT T)
{
    BIGINT R={0};
    int i,carry=0;
    for(i=0;i<S.cnt && i< T.cnt;i++)
    {
        int temp=S.v[i]+T.v[i]+carry;
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
int cmp(const void *a,const void *b)
{
    int *a1=(int *)a,*b1=(int *)b;
    return *a1-*b1;
}

int main()
{
    int n;
    scanf("%d",&n);
    LL a[10000],res=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        res=res^a[i];
    }
    if(res!=0) {
        printf("-1\n");
        return 0;
    }

    qsort(a,n,sizeof (a[0]),cmp);
    BIGINT sum={0,{0}};
    for(int i=1;i<n;i++)
    {
        sum=ADD(sum, int2BIG(a[i]));
    }
    for(int i=sum.cnt-1;i>=0;i--)
    {
        printf("%d",sum.v[i]);
    }
    printf("\n");
    return 0;
}