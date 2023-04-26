#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    int num[55];
    int len;
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    int len1=s1.len,len2=s2.len;
    int min=len1>len2?len2:len1;
    for(int i=0;i<min;i++)
    {
        if(s1.num[i]!=s2.num[i])
            return s2.num[i]-s1.num[i];
    }
    if(len1>len2)
        return -1;
    else return 1;
}

int main()
{
   int t;
   scanf("%d\n",&t);
   for(int i=0;i<t;i++)
   {
       int n;
       scanf("%d",&n);
       node a[n];
       for(int i=0;i<n;i++)
       {
           int k=0;
           while(scanf("%d",&a[i].num[k]))
           {
               if(a[i].num[k]==-1)
                break;
               k++;
           }
           a[i].len=k;
       }
       qsort(a,n,sizeof(a[0]),cmp);
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<a[i].len;j++)
                printf("%d ",a[i].num[j]);
            printf("\n");
       }

   }
}
