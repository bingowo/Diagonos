/**
两组数，各自异或完，再异或肯定为零
所有的数异或不为0，输出-1
异或满足结合律，交换律
除去最小的数，剩下的数做求和
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int cnt;
    int v[40];
}BIGINT;

int cmp(const void*a,const void*b)
{
    long long aa=*(long long *)a,bb=*(long long *)b;
    if(aa>bb) return -1;
    else if(aa<bb) return 1;
    else return 0;
}

BIGINT ll2bi(long long x)
{
    BIGINT re={0,{0}};
    for(;x>0;re.cnt++)
    {
        re.v[re.cnt]=x%10;
        x/=10;
    }
    return re;
}

BIGINT add(BIGINT x,BIGINT y)
{
    BIGINT sum={0,{0}};
    int max=x.cnt>y.cnt?x.cnt:y.cnt;
    int carry=0;
    for(;sum.cnt<max;sum.cnt++)
    {
        int tmp=x.v[sum.cnt]+y.v[sum.cnt]+carry;
        sum.v[sum.cnt]=tmp%10;
        carry=tmp/10;
    }
    if(carry)
        sum.v[sum.cnt++]=carry;
    return sum;
}

long long arr[10000]={0};
int main()
{
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%lld",&arr[i]);}
    qsort(arr,n,sizeof(arr[0]),cmp);
    long long tmp=arr[0];

    for(int i=1;i<n;i++)
    {
        tmp=tmp^arr[i];
    }
    if(tmp) printf("-1");
    else
    {
        BIGINT sum={1,{0}};
        for(int i=0;i<n-1;i++)
            sum=add(sum,ll2bi(arr[i]));
        for(int i=sum.cnt-1;i>=0;i--)
            printf("%d",sum.v[i]);
    }
    return 0;
}