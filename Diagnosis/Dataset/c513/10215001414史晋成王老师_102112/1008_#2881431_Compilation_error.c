#include<stdio.h>
#include<stdlib.h>
int* solve(int n)
{ int a[32],b=0,c;
 while(n)
 {a[b]=n%2;
  n=n/2;
  b++;
     
 }
 return a;
}
int main()
{int T,i,b,c,j,k; int a[32],d[32];
scanf("%d",&T);
for(i=0;i<T;i++)
{scanf("%d %d",&b,&c);
 a=solve(b); d=solve(c);
 j=0; k=0;
 while(a[j]||b[j])
 { if (a[j]!=b[j]) k++;
    j++;
 }
 printf("%d\n",k);
}
    
}