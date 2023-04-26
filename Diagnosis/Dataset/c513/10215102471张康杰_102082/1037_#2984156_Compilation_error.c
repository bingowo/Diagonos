#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    if(*(long long int*)a <= *(long long int*)b)
        return -1;
    else
        return 1;
}

int main()
{
    int m,n,i;
    scanf("%d %d",&n,&m);
    long long int input[n + 1] = {0};
    for(i = 1;i < n;i++)
    {
        scanf("%lld",&input[i]);
    }
    qsort(input,n,sizeof(long long int),cmp);
    long long int a[n + 1] = {0};
    for(i = 1;i < n;i++)
    {
        a[i] = input[i - 1] + input[i];
    }
    int sum,sum_cur = 0;
    for(i = 0;i <= n - m;i++)
    {
        sum_cur = input[i + m]*m - (a[i + m] - a[i]);
        if(sum_cur > sum)
            sum = sum_cur;
        sum_cur = 0;
    }
    printf("lld\n",sum);
}