#include <stdio.h>
#include <stdlib.h>
#define LL long long
#define N 100
typedef struct{
int cnt;
int v[N];
}BIGINT;
int cmp(const void*a,const void*b)
{
    long long A = *(long long*)a,B = *(long long*)b;
    return A-B;
}
BIGINT int2BIG(long long a)
{
    BIGINT A = {0,{0}};
    do{
        A.v[A.cnt++] = a%10;
        a/=10;
    }while(a>0);
    return A;
}
BIGINT ADD(BIGINT S,BIGINT T)
{
    BIGINT R = {0,{0}};
    int i,carry = 0;
    for(i = 0;i<S.cnt&&i<T.cnt;i++)
    {
        int temp = carry + S.v[i] + T.v[i];
        R.v[i] = temp%10;
        carry = temp/10;
    }
    while(i<S.cnt){
        int temp = carry + S.v[i];
        R.v[i] = temp%10;
        carry = temp/10;
        i++;
    }
    while(i<T.cnt){
        int temp = carry + T.v[i];
        R.v[i] = temp%10;
        carry = temp/10;
        i++;
    }
    if(carry) R.v[i++] = 1;
    R.cnt = i;
    return R;
}
int main()
{
    int n;
    scanf("%d",&n);
    LL a[10000],res = 0;
    int i;
    for(i = 0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        res = res^a[i];
    }
    if(res!=0) {printf("-1\n");return 0;}
    qsort(a,n,sizeof(long long),cmp);
    BIGINT ans = {0,{0}};
    for(i = 1;i<n;i++)
    {
        ans = ADD(ans,int2BIG(a[i]));
    }
    for(i = ans.cnt-1;i>=0;i--)
        printf("%d",ans.v[i]);
    printf("\n");
    return 0;
}
