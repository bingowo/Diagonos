#include <stdio.h>
#include <stdlib.h>

int cmp(const void*m,const void* n)
{
   int qm,qn;
   int*pm=m;
   int*pn=n;
   qm=*pm;
   qn=*pn;

   while(*pm!=0&&*pn!=0){*pm/=10;*pn/=10;}
   if(*pm==0&&*pn!=0)return 1;
   else if(*pm=0&&*pn==0)return -1;
   else{if(qm>qn)return 1;else if(qm==qn)return 0;else return -1;}
}
int main()
{
   int i=0,a[1000001],j=0;
   while(scanf("%d",&a[i])!=EOF)i++;

   qsort(a,i+1,sizeof(a[0]),cmp);
   while(j<=i){printf("%d",a[j]);j++;}
   return 0;
}
