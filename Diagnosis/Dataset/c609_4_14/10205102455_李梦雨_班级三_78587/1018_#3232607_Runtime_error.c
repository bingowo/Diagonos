#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    int *s1,*s2;
    s1=(int *)a;
    s2=(int *)b;
    return *s1-*s2;
}

int main()
{
    long long int a[100000];
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a),cmp);
    long long int sum=0;
    int j=0;
    for(int i=0;i<n/2;i++)
    {
        sum=sum+a[j+1]-a[j];
        j+=2;
    }
    printf("%lld\n",sum);
    return 0;
}