#include <stdio.h>
#include <stdlib.h>

typedef struct { int x,d; } PAIR;

digits(int n)
{ int r=0;  if (n<0) /*r++,*/n*=-1; do r++;  while (n/=10); return r; }
 int cmp(const void* e1,const void* e2)
 { PAIR *n1=(PAIR*)e1,*n2=(PAIR*)e2; int delta;
    return (delta=n2->d - n1->d)?delta:(n1->x - n2->x);
 }
int main()
{ PAIR *a=(PAIR*)malloc(1000000*sizeof(PAIR)); int n=0,i;
   while (scanf("%d",&((a+n)->x))!=EOF)  (a+n)->d=digits((a+n)->x),n++;
   qsort(a,n,sizeof(a[0]),cmp);
   for(i=0;i<n;i++) printf("%d%c",a[i].x,i<n-1?' ':'\n');

   return 0;
}