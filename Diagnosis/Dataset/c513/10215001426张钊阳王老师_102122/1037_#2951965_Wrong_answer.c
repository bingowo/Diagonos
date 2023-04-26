#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a1,const void *b1);
long long sum(long long int* a,int m);
int main()
{
    int n,m;
    int i,j;
    long long int ans=0;
    long long int max=0;
    scanf("%d",&n);
    scanf("%d",&m);
    long long int a[1000000];
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=0;i<=n-m;i++)
    {
        long long int cp[1000000];
        int count=0;
        int g=0;
        for(j=i;count<m;count++,j++)
        {
            cp[g]=a[j];
            g++;
        }
        if(sum(cp,m)>=max) max=sum(cp,m);
    }
    printf("%lld",max);
    return 0;
}


int cmp(const void *a1,const void *b1)
{
    int a=*(int *)a1;
    int b=*(int *)b1;
    return b-a;
}

long long sum(long long int* a,int m)
{
    long long int ans=0;
    for(int i=m-1;i>=0;i--)
        ans+=a[i]-a[0];
    return ans;
}
