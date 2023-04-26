#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    long long num;
    int h;
}node;
int cmp1(const void *a,const void *b)
{
    int s1=*(int*)a;
    int s2=*(int*)b;
    return s1-s2;
}
int cmp2(const void *a,const void *b)
{
    int s1=*(int*)a;
    int s2=*(int*)b;
    return s2-s1;
}
int main()
{
   int t;
   scanf("%d\n",&t);
   for(int i=0;i<t;i++)
   {
       int n;
       scanf("%d",&n);
       int a[n],b[n];
       for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
       for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
       qsort(a,n,sizeof(a[0]),cmp1);
       qsort(b,n,sizeof(b[0]),cmp2);
       int ans=0;
       for(int i=0;i<n;i++)
       {
           ans=ans+a[i]*b[i];
       }
       printf("case #%d:\n%d\n",i,ans);
   }
}
