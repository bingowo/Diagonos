#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    long long x,y;
    unsigned long long x1,y1;
    unsigned long long l;
}node;
int cmp(const void *a,const void *b)
{
    int s1=*(int*)a;
    int s2=*(int*)b;
    //return s1-s2;
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
    printf("%lld",ans);
}
