#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return (int *)a-(int *)b;
}

int main()
{
    int n,i;
    long long int all;
    scanf("%d",&n);
    int shu[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",shu[i]);
    }
    qsort(shu,n,sizeof(shu[0]),cmp);
    for(i=0;i<n;i+=2)
    {
        all=all+shu[i+1]-shu[i];
    }
    printf("%lld",all);
    return 0;
}
