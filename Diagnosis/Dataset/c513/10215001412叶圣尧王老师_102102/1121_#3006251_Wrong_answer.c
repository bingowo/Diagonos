#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void val(int*d,int*a,int n,int m)
{
    int i,j;
    if(n>0)
    {
        val(d,a,n-1,m+a[n-1]);
        val(d,a,n-1,m-a[n-1]);
    }
    else
        d[abs(m)]=1;
}

int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int n;scanf("%d",&n);
    int i,j,sum=0;int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int d[sum+1];
    for(i=0;i<=sum;i++)
         d[i]=0;
    for(i=0;i<n;i++)d[a[i]]=1;
    val(d,a,n,0);
    for(i=1;i<=sum;i++)printf("%d",d[i]);
}
