#include <stdio.h>
#include <stdlib.h>

int ascmp(const void*a,const void *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int *x,i=0,sum=0;
    int n=0;
    scanf("%d",&n);
    x=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
    i--;
    qsort(x,i,4,ascmp);
    for(;i>=0;i=i-2)
        sum+=x[i]-x[i-1];
    printf("%d",sum);
    return 0;
}
