#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LL long long int
#define N 10000000

int cmp(const void *q1,const void *q2)//将数从大到小排序
{
    LL *p1=(LL *)q1;
    LL *p2=(LL *)q2;

    if(*p1 < *p2) return 1;
    else if(*p1 >= *p2) return -1;
}

int main()
{
    int n;  scanf("%d",&n);

    LL a[N];
    for(LL i=0;i<n;i++)
        scanf("%lld",&a[i]);

    qsort(a,n,sizeof(LL),cmp);

    LL sum=0;
    for(LL j=0;j<n;j+=2)
    {
        LL temp=a[j]-a[j+1];
        sum+=temp;
    }

    printf("%lld",sum);

    return 0;
}