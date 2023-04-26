#include <stdio.h>
#include <stdlib.h>

int cmp(const void* x,const void* y)
{
    int* a=(int*)x;
    int* b=(int*)y;
    return *a-*b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d\t",a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    int sum;
    for(int i=0;i<n/2;i++)
    {
        int temp;
        temp=a[i+1]-a[i];
        if(temp>=0) temp=temp;
        else temp=-temp;
        sum+=temp;
    }
    printf("%d",sum);
    free(a);
    return 0;
}

