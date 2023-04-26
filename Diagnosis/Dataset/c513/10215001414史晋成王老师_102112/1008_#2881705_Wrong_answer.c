#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int* solve(int n)
{ int b=0,c; int* a;
  a=(int*) malloc(sizeof(int)*32);
 
 while(n)
 {a[b]=n%2;
  n=n/2;
  b++;
     
 }

 return a;
  free(a);
}
int main()
{int T,i,b,c,j,k,h; int a[32],d[32];
scanf("%d",&T);
for(i=0;i<T;i++)
{scanf("%d %d",&b,&c);
 strcpy(a,solve(b)); 
  h=0;
  while(c)
 {d[h]=c%2;
  c=c/2;
  h++;
     
 }
 printf("%d %d",d[1],a[1]);
 j=0; k=0;
 while ((a[j]!=0)||(d[j]!=0))
 { if (a[j]!=d[j]) k++;
    j++;
 }
printf("%d\n",k);
}
    
}