#include <stdio.h>
#include <stdlib.h>

int cmp(const void*m,const void* n)
{
    int*pm=m;
    int*pn=n;
    if(*pm<*pn)return 1;
    else if(*pm==*pn)return 0;
    else return -1;
}
int main()
{
    int i=0;
    long long int n;
    scanf("%lld\n",&n);
    long long int a[1000001];

    while(i<n){scanf("%lld",&a[i]);i++;}
    long long *p=a;
    qsort(a,n,sizeof(a[0]),cmp);
    long long int min=0;
    for(int j=0;j<n/2;j++)min+=p[2*j+1]-p[2*j];
    printf("%lld",min);
    return 0;
}
