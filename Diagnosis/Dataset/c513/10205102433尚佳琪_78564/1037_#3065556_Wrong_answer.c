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
    int ans=0;
    for(int i=0;i<m;i++)
        ans+=a[m-1]-a[i];
    //printf("%lld\n",ans);
    int i;
    for(i=m-1;i<n;i++)
    {
        long long temp=0;
        for(int j=i+1-m;j<=i;j++)
        {
            temp=temp+a[i]-a[j];
           // printf("%lld\n",temp);
        }
       // printf("%lld\n",temp);
        ans=ans<temp?ans:temp;
    }

    printf("%lld",ans);
}
