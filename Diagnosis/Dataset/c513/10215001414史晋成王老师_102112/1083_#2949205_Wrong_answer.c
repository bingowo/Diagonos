#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int i,j,m,n,o,p,q,s,a[1000000],t,k,flag=0,g;
scanf("%d",&t);
for(i=0;i<t;i++)
{ scanf("%d",&n);
  a[0]=1;s=0;
 for(j=1;j<=n;j++)
   s+=log10(j);
   s++;
   for(j=0;j<s;j++)
   a[j]=0;
   g=0;
   for(k=1;k<=n;k++)
   {for(j=0;j<s;j++)
    { t=a[j]*k+g;
        a[j]=t%10;
        g=t/10;
    }}
 
 s=0;
 while(a[s]==0)
 s++;
 printf("case #%d:\n",i);
 printf("%d\n",s);
}
    
}