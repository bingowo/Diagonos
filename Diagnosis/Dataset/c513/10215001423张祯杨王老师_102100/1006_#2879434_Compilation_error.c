#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() 
{
 int T;
  long long a[20000];
 scanf("%d\n",&T);
 for(i=0;i<T;i++){
  scanf("%d",&d);
  for(j=0;j<d;j++) scanf("%ld",&a[j]);
  printf("case #%d:\n",i);
  qsort(a,d,sizeof(long long),cmp);
  for (j=0;j<d;j++) printf("%ld%c",a[j],j!=d-1?' ':'\n');
 }
 
 return 0;
}
 