#include <stdio.h>
#include <stdlib.h>

int cmp(const int m,const int n)
{
    if(m>=n)return 1;
    else return m-n;
}
int main()
{
    int i=0;
    long long int n;
    scanf("%lld\n",&n);
    long long int a[1000001];

    while(i<n){scanf("%lld",&a[i]);i++;}
    qsort(a,n,sizeof(a[0]),cmp);
    long long int min=0;
    for(int j=0;j<n/2;j++)min+=a[2*j+1]-a[2*j];
    printf("%lld",min);
    return 0;
}
