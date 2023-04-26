#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    long long d1,d2;
    d1=*((long long *)a);
    d2=*((long long *)b);
    if(d1<=d2) return -1;
    else if(d1>d2) return 1;
}
int main()
{
    long long n;
    long long a[100008]={0};
    scanf("%lld",&n);
    int i=n;
    while(i--)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int sum=0;
    for(int j=0;j<n;j+=2)
    {
        sum+=a[j+1]-a[j];
    }
    printf("%d",sum);
    return 0;
}
