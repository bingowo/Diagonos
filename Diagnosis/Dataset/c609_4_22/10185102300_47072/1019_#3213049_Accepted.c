#include <stdio.h>
#include <stdlib.h>

//typedef struct { int x,d; } PAIR;

digits(int n)
{ int r=0;  if (n<0) /*r++,*/n*=-1; do r++;  while (n/=10); return r; }
 int cmp(const void* e1,const void* e2)
 { int n1=*(int*)e1,n2=*(int*)e2; int delta;
    return (delta=digits(n2)-digits(n1))?delta: n1-n2;
 }
int main()
{ int *a=(int*)malloc(1000000*sizeof(int)); int n=0,i;
   while (scanf("%d",a+n)!=EOF)  n++;
   qsort(a,n,sizeof(a[0]),cmp);
   for(i=0;i<n;i++) printf("%d%c",a[i],i<n-1?' ':'\n');

   return 0;
}


