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
 free(a);
 return a;

}
int main()
{int T,i,b,c,j,k; int a[32],d[32];
scanf("%d",&T);
for(i=0;i<T;i++)
{scanf("%d %d",&b,&c);
 strcpy(a,solve(b)); strcpy(d,solve(c));
 printf("%d %d\n",a[0],d[0]);
 j=0; k=0;
 while(a[j]||d[j])
 { if (a[j]!=d[j]) k++;
    j++;
 }

}
    
}