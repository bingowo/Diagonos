#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int cmp(const void *a,const void *b)
{
    int s1=*(int*)a;
    int s2=*(int*)b;
    return s1-s2;
}

int main()
{
   char c;
   scanf("%c\n",&c);
   int a[150],k=0;
   while(scanf("%d",&a[k])!=EOF)
   {
       k++;
   }
   qsort(a,k,sizeof(a[0]),cmp);
   for(int i=0;i<k-1;i++)
   {
       if(a[i]!=a[i+1])
        printf("%d ",a[i]);
   }
   printf("%d",a[k-1]);
}
