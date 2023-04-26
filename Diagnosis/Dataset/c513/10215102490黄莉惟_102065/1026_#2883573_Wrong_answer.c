#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
    long long int n;
    long long int a[10000];
    long long int i=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",a+i);
    }
    Sort(a,n);
    for (i=0;i<n;i++) printf("%lld%c",a[i],i!=n-1?' ':'\n');
}
int cmp(const void* a,const void* b)
{  
    long long int ua=*(long long int*)a;
    long long int ub=*(long long int*)b;
    return ua<ub?-1:1;


}
void Sort(long long int *p, long long int n)
{
    qsort(p,n,sizeof(long long int),cmp);
}