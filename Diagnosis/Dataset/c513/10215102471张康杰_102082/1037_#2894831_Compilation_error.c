#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(int*)a - *(int*)b;
}
int main()
{
    int m,n,i;
    scanf("%d %d",&n,&m);
    long long int input[n];
    for(i = 0;i < n;i++)
    {
        scanf("%lld",&input[i]);
    }
    qsort(input,n,sizeof(int),cmp);
    long long int sum_min = 0,sum_cur = 0;
    int flag = 1;
    for(i = m - 1;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            sum_cur += input[i] - input[i - j];
        }
        if(flag)
        {
            flag = 0;
            sum_min = sum_cur;
        }
        if(sum_cur < sum_min)
        {
            sum_min = sum_cur;
            sum_cur = 0;
        }
    }
    printf("%lld",sum_max);

    return 0;
}
