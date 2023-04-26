#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    if((int *)a>(int *)b)
        return 1;
    else
        return -1;
}

int main()
{
    int n,i;
    long long int all=0;
    scanf("%d",&n);
    int shu[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&shu[i]);
    }
    qsort(shu,n,sizeof(shu[0]),cmp);
    for(i=0;i<n;i+=2)
    {
        all=all+shu[i+1]-shu[i];
    }
    printf("%lld",all);
    return 0;
}
