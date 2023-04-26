#include <stdio.h>
#include <stdlib.h>
typedef struct{
    long long int r;
    long long int h;
    long long int di;
    long long int ce;
}zhu;
int cmp(const void *a,const void *b)
{
    zhu x;
    zhu y;
    x=*(zhu*)a;
    y=*(zhu*)b;
    if((y.ce-x.ce)>0) return 1;
    else if(x.ce==y.ce) return 0;
    else return -1;
}
long long int max(long long int a,long long int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    zhu a[1001];
    long long int ans;
    long long int sum=-1;
    for(int k=0;k<n;k++)
    {
        scanf("%lld%lld",&a[k].r,&a[k].h);
        a[k].di=a[k].r*a[k].r;
        a[k].ce=2*a[k].r*a[k].h;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int r=0;r<m;r++)
    {
        ans=a[r].ce+a[r].di;
        int count=1;
        for(int j=0;j<n&&count<m;j++)
        {
            if(r==j||a[r].r<a[j].r) continue;
            ans=ans+a[j].ce;
            count++;
        }
        sum= max(sum,ans);
    }
    printf("%lld",sum);
    return 0;
}