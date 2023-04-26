#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long a[1000],b[1000],sum=0;
int main()
{
    int cmp(const void*x,const void*y)
    {
        return *(long long*)y-*(long long*)x;
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<n/2;i++){
        b[i]=a[2*i]-a[2*i+1];
        sum+=b[i];
    }
    printf("%d",sum);

    return 0;
}