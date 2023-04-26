#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define N 1000000

int cmp(const void*m,const void* n)
{
   double qm,qn;
   int*pm=m;
   int*pn=n;
   qm=*pm;
   qn=*pn;

   while(qm!=0&&qn!=0){qm/=10;qn/=10;}
   if(qm==0&&qn!=0)return 1;
   else if(qm==0&&qn==0)return -1;
   else{if(*pm>*pn)return -1;else if(*pm==*pn)return 0;else return 1;}
}
int main()
{
    int i=0,a[N],j=0;
   int*p=(int*)malloc(N*sizeof(int));

   while(scanf("%d",&a[i])!=EOF)i++;

   qsort(a,i-1,sizeof(a[0]),cmp);
   while(j<=i-1){printf("%d ",a[j]);j++;}
   free(p);
   return 0;
}
