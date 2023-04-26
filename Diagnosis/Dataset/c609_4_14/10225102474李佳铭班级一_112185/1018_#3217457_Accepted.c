#include <stdio.h>
#include <stdlib.h>

int cmp(void*a,void*b)
{
    int A = *(int*)a;
    int B = *(int*)b;
    if(A != B)
        return A - B;
    else
    {
        return 1;
    }
}

int main()
{
    int n;
    int a[1000000];
    int sum = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i = 0; i < n; i = i + 2)
    {
        sum = sum + (a[i + 1] - a[i]);
    }
    printf("%d",sum);
    return 0;
}
