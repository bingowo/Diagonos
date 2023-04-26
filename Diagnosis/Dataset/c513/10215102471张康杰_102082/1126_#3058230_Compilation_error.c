#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int LLU;

int cmp(const void*a,const void*b)
{
    return *(LLU)a - *(LLU)b;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    LLU ar[n],temp;
    for(i = 0;i < n;i++)
        scanf("%llu",ar[i]);
    temp = ar[0];
    for(i = 1;i < n;i++)
        temp ^= ar[i];
    if(temp != 0)
    {
        printf("-1");
        return 0;
    }
    qsort(ar,LLU,n,cmp);
    LLU sum = 0;
    for(i = 1;i < n;i++)
        sum += ar[i];
    printf("%llu",sum);
    return 0;
}
