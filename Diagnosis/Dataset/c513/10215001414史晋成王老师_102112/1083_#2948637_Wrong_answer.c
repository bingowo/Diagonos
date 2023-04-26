#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int i,j,m,n,o,p,q,s,a[1000000],t,flag=0;
scanf("%d",&t);
for(i=0;i<t;i++)
{ scanf("%d",&n);
  a[0]=1;a[1]=-1;
 for(j=1;j<=n;j++)
 { p=0; flag=0;
   while(a[p]!=-1)
  { flag=0;
    a[p]*=j;
    a[p]+=flag;
    if(a[p]>9) {a[p]-=10;flag=1;}
    p++;
  }
  a[p]+=flag;if(a[p]==0) a[p+1]=-1;
 }
 s=0;
 while(a[s]==0)
 s++;
 printf("case #%d:\n",i);
 printf("%d\n",s);
}
    
}