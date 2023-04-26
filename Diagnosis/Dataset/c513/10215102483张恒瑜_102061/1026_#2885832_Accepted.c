#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(long long*)a >*(long long*)b ? -1 : 1;
}

int main()
{
    int i,num;
    scanf("%d",&num);
    long long point[num];
    for(i=0;i<num;i++)
        scanf("%lld",&point[i]);
    qsort(point,num,sizeof(point[0]),cmp);
    long long sum=0;
    for(i=0;i<num;i+=2)
        sum+=llabs(point[i]-point[i+1]);

    printf("%lld",sum);
    return 0;
}