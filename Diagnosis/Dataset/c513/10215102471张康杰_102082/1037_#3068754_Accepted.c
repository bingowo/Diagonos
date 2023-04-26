#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//前缀和
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
    long long int*input,*a;
    input = (long long int*)malloc(sizeof(long long int) * (n + 1));
    a = (long long int*)malloc(sizeof(long long int) * (n + 1));
    memset(input,0,sizeof(long long int)*(n + 1));
    memset(a,0,sizeof(long long int)*(n + 1));   
    for(i = 1;i <= n;i++)
    {
        scanf("%lld",&input[i]);
    }
    qsort(input,n + 1,sizeof(long long int),cmp);
    for(i = 1;i <= n;i++)
    {
        a[i] = a[i - 1] + input[i];
    }
    long long int sum,sum_cur = 0;
    int flag = 1;
    for(i = 0;i <= n - m;i++)
    {
        sum_cur = input[i + m]*m - (a[i + m] - a[i]);
        if(flag)
        {
            sum = sum_cur;
            flag = 0;
        }
        if(sum_cur < sum)
            sum = sum_cur;
        sum_cur = 0;
    }
    free(a);
    free(input);
    printf("%lld\n",sum);
    return 0;
}