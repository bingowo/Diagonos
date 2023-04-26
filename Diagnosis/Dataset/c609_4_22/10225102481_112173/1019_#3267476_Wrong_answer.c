#include <stdio.h>
#include <stdlib.h>

int cmp(const void*m,const void* n)
{
   double qm,qn;
   int*pm=m;
   int*pn=n;
   qm=*pm;
   qn=*pn;

   while(qm!=0&&qn!=0){qm/=10;qn/=10;}
   if(qm==0&&qn!=0)return 1;
   else if(qm!=0&&qn==0)return -1;
   else{if(*pm>*pn)return 1;else if(*pm==*pn)return 0;else return -1;}
}
int main()
{
   int i=0,a[1000001],j=0;
   while(scanf("%d",&a[i])!=EOF)i++;

   qsort(a,i,sizeof(a[0]),cmp);
   while(j<=i-1){printf("%d ",a[j]);j++;}
   return 0;
}