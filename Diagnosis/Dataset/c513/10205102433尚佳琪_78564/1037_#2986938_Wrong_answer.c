#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void *b)
{
    long long s1=*(long long *)a;
    long long s2=*(long long *)b;
    if(s1>s2)
        return 1;
    else
        return -1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
   /* for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");*/
    long long ans=0,temp=0;
    int i;
    int temp2;
    temp2=m;
    for(int j=0;j<m;j++)
    {
        ans=ans+a[m-1]-a[j];
    }
    temp=ans;
    for(i=0;i<(n-m);i++)
    {
         temp=temp+a[temp2]-a[temp2-1]-(a[i+m-1]-a[i]);
         temp2++;
        /*for(int j=i;j<i+m;j++)
        {
            temp=temp+a[i+m-1]-a[j];
            //printf("%lld",temp);
        }*/
      //  if(ans==0)ans=temp;
        ans=temp<ans?temp:ans;
      // printf("%lld\n",ans);
        temp=0;
    }
    if(i==0)
    {
        for(int j=0;j<m;j++)
        {
            ans=ans+a[m-1]-a[j];
        }
    }
    printf("%lld",ans);
    return 0;
}

