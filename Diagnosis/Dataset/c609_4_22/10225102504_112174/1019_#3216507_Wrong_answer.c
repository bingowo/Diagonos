#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   int cmp(const void *q1,const void *q2){
   int*p1=(int*)q1;
   int*p2=(int*)q2;
   if(abs(*p1)/10>abs(*p2)/10)
    return 1;
   else if(abs(*p1)/10<abs(*p2)/10)
    return -1;
   else
    return(*p2-*p1);
   }
   int a[1000];
   int i=0;
   while(scanf("%d ",&a[i])!=EOF){
    i++;
   }
   qsort(a,i,sizeof(int),cmp);
   for(int j=0;j<i;j++){
    printf("%d ",a[j]);
   }
    return 0;
}
