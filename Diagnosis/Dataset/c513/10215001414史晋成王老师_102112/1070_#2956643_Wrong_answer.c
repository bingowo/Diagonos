#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int solve(int n)
{ int i;
  if(n==1||n==2) {i=0; return i;}
 else if (n==3) {i=7; return i;}
 else return (solve(n-1)+solve(n-1)-pow(2,n-3));
}
int main()
{ int n,i,j;
 while(scanf("%d",&n)!=EOF)
 { if(n==-1) break;
   else
   { j=solve(n);
     printf("%d\n",j);
   }
 }
    
}