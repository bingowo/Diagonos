#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void* p1,const void* p2)
{
    long long int a,b;
    a=*(int*)p1;
    b=*(int*)p2;
    if(a>b) return 1;
    else return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    long long int s[10000],sum=0;
    for(int j=0;j<n;j++)
        scanf("%lld",&s[j]);
    qsort(s,n,sizeof(long long int),cmp);
    for(int i=0;i<n;i=i+2){
        sum=sum+s[i+1]-s[i];
    }
    printf("%lld",sum);
    return 0;
}