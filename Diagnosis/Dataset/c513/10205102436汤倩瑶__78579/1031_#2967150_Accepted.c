#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

int cmp(const void*a,const void*b)
{
      return *((int*)a)-*((int*)b);
}
int cmp2(const void*a,const void*b)
{
      return *((int*)b)-*((int*)a);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int *a=(int*)malloc(sizeof(int)*n);
          int *b=(int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        for(int j=0;j<n;j++)
        {
            scanf("%d",&b[j]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(b[0]),cmp2);
        printf("case #%d:\n",i);
        int ans=0;
        for(int j=0;j<n;j++)
        {
           ans+=a[j]*b[j];
        }

        printf("%d\n",ans);
    }
}
