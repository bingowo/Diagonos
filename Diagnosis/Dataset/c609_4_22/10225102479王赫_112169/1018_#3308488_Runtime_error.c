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
    scanf("%d\n",&n);
    long long int *a=(long long int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n;i++) scanf("%lld",a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    long long int sum=0;
    int i=0;
    while(i<n-1){
        int temp;
        temp=a[i+1]-a[i];
        if(temp>=0) temp=temp;
        else temp=-temp;
        sum+=temp;
        i+=2;
    }
    printf("%d",sum);
    free(a);
    return 0;
}
