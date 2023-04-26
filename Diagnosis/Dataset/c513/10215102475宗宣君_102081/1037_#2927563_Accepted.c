#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)
{
    if(*(long long int*)a>=*(long long int*)b) return -1;
    else return 1;

}
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    long long int a[n],b[n],res = 0,min;
    for(i = 0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(long long int),cmp);
    for(i = 1;i<m;i++)
        res = res+a[0]-a[i];
        min = res;
    for(i = 1;i<=n-m;i++)
    {
        res = res- (a[i-1]-a[i])*(m-1)+a[i]-a[i+m-1];
        min = min<res?min:res;
    }
    printf("%lld",min);
}
