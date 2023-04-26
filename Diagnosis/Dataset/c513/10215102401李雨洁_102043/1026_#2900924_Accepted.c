#include <stdio.h>
#include <stdlib.h>

int cmp ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[100001] = {0};
    for(int i = 0; i < n; i++)
    {
        scanf("%d ",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int sum = 0;
    for(int i = 0; i < n; i += 2)
    {
        sum+=a[i+1]-a[i];
    }
    printf("%d\n",sum);
    return 0;
}