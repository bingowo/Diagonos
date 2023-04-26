#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long int s[100005];
int cmp_1(const void *a, const void *b){
        return *(int *)a-*(int *)b;}
int main()
{
    long long int n;scanf("%lld",&n);
    long long int m=n;
    long long int i=0;
    memset(s,0,sizeof(s));
    while(m--)
       scanf("%lld",&s[i++]);
    qsort(s,n,sizeof(long long int),cmp_1);
    long long int re=0;
    for(int j=0,k=1;k<=n-1;j+=2,k+=2){
        re+=fabs(s[k]-s[j]);
    }
    printf("%lld",re);
    return 0;
}
