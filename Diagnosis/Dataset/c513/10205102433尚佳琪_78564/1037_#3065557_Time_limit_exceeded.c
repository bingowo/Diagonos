#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void *a,const void *b)
{
    long long s1=*(long long*)a;
    long long s2=*(long long*)b;
    if(s1>s2)
        return 1;
    else
        return -1;
}

int main()
{
   int n,m;
   scanf("%d %d",&n,&m);
   long long a[n];
   for(int i=0;i<n;i++)
   {
       scanf("%lld",&a[i]);
   }
    qsort(a,n,sizeof(a[0]),cmp);
    unsigned long long ans=0;
    for(int i=0;i<m;i++)
        ans+=a[m-1]-a[i];
    for(int i=m-1;i<n;i++)
    {
        unsigned long long temp=0;
        for(int j=i+1-m;j<=i;j++)
        {
            temp=temp+a[i]-a[j];
        }
        ans=ans<temp?ans:temp;
    }

    printf("%lld",ans);
}
