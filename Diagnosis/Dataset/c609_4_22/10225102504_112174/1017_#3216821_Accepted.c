#include <stdio.h>
#include <stdlib.h>

int main()
{
   char o;
   int i=0;
   int a[10000];
   scanf("%c",&o);
   while(scanf("%d ",&a[i])!=EOF)
   {
       i++;
   }
   int cmp(const void *q1,const void *q2){
   int*p1=(int*)q1;
   int*p2=(int*)q2;
   if (o=='A')
    return(*p1-*p2);
   else if(o=='D')
    return(*p2-*p1);
   }
   qsort(a,i,sizeof(a[0]),cmp);
   for(int j=0;j<i;j++){
    if(a[j]!=a[j+1])
        printf("%d ",a[j]);
   }
    return 0;
}
