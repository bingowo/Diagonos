#include <stdio.h>
#include <stdlib.h>

int main()
{
   int cmp(const void *q1,const void *q2){
   return *(int*)q1-*(int*)q2;
   }
   int n;
   scanf("%d",&n);
   int point[n];
   for(int i=0;i<n;i++){
    scanf("%d",&point[i]);
   }
   qsort(point,n,sizeof(int),cmp);
   int min=0;
   for(int j=0;j<n/2;j++){
    min+=point[2*j+1]-point[2*j];
   }

printf("%d",min);
    return 0;
}