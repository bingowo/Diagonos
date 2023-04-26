#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void *b)  // 升序
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int n;
    scanf("%d",&n);
    int* L;
    L = (int *) malloc(n*sizeof(int));
    for (int i = 0;i<n;i++)  scanf("%d",&L[i]);
    qsort(L,n,sizeof(int),cmp);
    long long int sum = 0;
    for (int i = 0;i<n;i++)
    {
        sum += L[i+1] - L[i];
        ++i;
    }
    printf("%lld",sum);
    return 0;
}
