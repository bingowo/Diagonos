#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int n;
    scanf("%d",&n);
    int s[n];
    for(int i=0; i<n; i++)
        scanf("%d",&s[i]);
    qsort(s,n,sizeof(int),cmp);
    int sum=0;
    for(int i=0; i<n-1; i+=2)
    {
        sum+=s[i+1]-s[i];
    }
    printf("%d",sum);
    return 0;
}
