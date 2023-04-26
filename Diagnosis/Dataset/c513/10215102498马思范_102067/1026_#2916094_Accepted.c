#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    if(x>y)
        return -1;
    else
        return 1;
}
int main()
{
    int n;
    long long a[100000];
    long long b[100000];
    long long sum=0;
    scanf("%d",&n);
    for(int m=0;m<n;m++)
    {
        scanf("%lld",&a[m]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int j=0;j<n;j+=2)
    {
        sum=sum+a[j]-a[j+1];
    }
    printf("%lld",sum);
    return 0;
}