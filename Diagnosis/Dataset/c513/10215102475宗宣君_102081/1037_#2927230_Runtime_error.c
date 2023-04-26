#include<stdio.h>
#include<stdlib.h>
int p = 0;
int cmp(const void*a,const void*b)
{
    if(*(long long int*)a<*(long long int*)b) return -1;
    else return 1;

}
void combination(long long int*a,int n,int m,int r,int begin,long long int*b,long long* res)
{
    int i,j;
    for(i = begin;i<=n-m;i++)
    {
        b[m-1] = a[i];
        if(m==1)
    {
        for(j = r-1;j>0;j--)
        {
           res[p] = res[p] + b[0] - b[j];
        }
        p++;

    }
        else
        combination(a,n,m-1,r,i+1,b,res);
    }
}
int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    long long int a[n],b[n],res[1000] = {0},min;
    for(i = 0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(long long int),cmp);
    combination(a,n,m,m,0,b,res);
    min = res[0];
    for(i = 1;i<p;i++)
       min = min<res[i]?min:res[i];
    printf("%lld",min);





}
