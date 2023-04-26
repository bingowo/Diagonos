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
    long long int n;
    scanf("%lld",&n);
    long long int *s,sum=0;
    s=(long long int*)malloc(n*sizeof(long long int));
    for(int j=0;j<n;j++)
        scanf("%lld",&s[j]);
    qsort(s,n,sizeof(long long int),cmp);
    for(int i=0;i<n;i=i+2){
        sum=sum+s[i+1]-s[i];
    }
    printf("%lld",sum);
    return 0;
}
