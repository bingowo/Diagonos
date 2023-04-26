#include <stdio.h>
#include <stdlib.h>
int longlongcmp(long long int a,long long int b)
{
    if(a == b)
        return 0;
    else if(a < b)
        return -1;
    else
        return 1;
}
int binary(long long int x)
{
    int i,count = 0;
    for(i = 0;i < 64;i++)
    {
        if((x&(1LL<<i)) != 0)
            count++;
    }

    return count;

}
int cmp(const void*a, const void*b)
{
    long long int c,d;
    c = *(long long int*)a;
    d = *(long long int*)b;
    if(binary(c) == binary(d))
        return longlongcmp;
    else
        return binary(d) - binary(c);

}
int main()
{
    int T, i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        long long int N;
        int j;
        scanf("%lld",&N);
        long long int input[N];
        for(j = 0;j < N;j++)
            scanf("%lld",&input[j]);
        qsort(input, N, sizeof(input[0]), cmp);
        printf("case #%d:\n",i);
        for(j = 0;j < N;j++)
            printf("%lld%c",input[j],(j==N - 1)?'\n':' ');
    }
    return 0;
}