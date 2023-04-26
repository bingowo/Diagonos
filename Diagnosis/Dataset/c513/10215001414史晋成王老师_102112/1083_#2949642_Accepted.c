#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int i,m,n,o,p,q,a[1000000],t,k,flag=0,g,l,T;
  double j,s;
scanf("%d\n",&T);
for(i=0;i<T;i++)
{ scanf("%d",&n);
  a[0]=1;s=0;
 for(j=1;j<=n;j++)
   s+=log10(j);
   m=(int)s+1;
   for(l=1;l<m;l++)
   a[l]=0;
   g=0;
   for(k=1;k<=n;k++)
   {for(l=0;l<m;l++)
    { t=a[l]*k+g;
        a[l]=t%10;
        g=t/10;
    }}
 
 p=0;
 while(a[p]==0)
 p++;
 printf("case #%d:\n",i);
  printf("%d\n",p);
}
    
}