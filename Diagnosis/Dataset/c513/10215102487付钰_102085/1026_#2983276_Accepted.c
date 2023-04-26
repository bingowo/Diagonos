#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
long long int  llabs(long long int x)
   { return x < 0 ? -x : x;}

int cmp(const void *a, const void *b)
{
	long long int na = *(long long int *)a;
	long long int nb = *(long long int *)b;
	return na > nb ? 1 : -1 ;
}
int main()
{
    int n;
    long long int out;
    scanf("%d",&n);
    long long int a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int j=0;j<n;j+=2){
        out += llabs(a[j]-a[j+1]);
    }
    printf("%lld",out);
}
