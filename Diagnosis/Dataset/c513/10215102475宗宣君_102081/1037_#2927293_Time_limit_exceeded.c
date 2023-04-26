#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)
{
    if(*(long long int*)a>=*(long long int*)b) return -1;
    else return 1;

}
int main()
{
    int n,m,i,p = 0,j;
    scanf("%d %d",&n,&m);
    long long int a[n],b[n],res[10000000] = {0},min;
    for(i = 0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(long long int),cmp);
    for(i = 0;i<=n-m;i++)
    {for(j = i+1;j<i+m;j++)
        res[p] = res[p]+ a[i] - a[j];
        p++;}
    min = res[0];
    for(i = 1;i<p;i++)
       min = min<res[i]?min:res[i];
    printf("%lld",min);
}
