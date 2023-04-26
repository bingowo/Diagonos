#include <stdio.h>
#include <stdlib.h>

int ncmp(const void *a,const void *b)
{
    return *(long long int *)b > *(long long int *)a;
}

int scmp(const void*a,const void*b)
{
    return *(long long int *)a > *(int *)b;
}

int main()
{
    int n,m;
    int i;
    scanf("%d %d\n",&n,&m);
    long long int number[n];
    for(i=0;i<n;i++)
        scanf("%lld",&number[i]);
    //对输入的数字从大到小进行排序
    qsort(number,n,sizeof(number[0]),ncmp);

    //求两两间的差值
    long long int a[n];
    for(i=0;i<n-1;i++)
        a[i] = number[i]-number[i+1];

    //求n-m+1种情况下的差值
    int count;
    count = n-m+1;
    long long int S[n];
    int t=m;
        //求S1（记为S0）
    for(i=0;t>0;i++)
    {
        S[0] += a[i]*(t-1);
        t--;
    }
        //求S2-Scount（记为S1）
    t=m;
    for(i=1;i<count;i++)
        S[i]=S[i-1]-a[i-1]*(t-1)+(number[i] - number[i+m-1]);

    //排序
    qsort(S,count,sizeof(S[0]),scmp);
    printf("%lld",*S);
    return 0;
}