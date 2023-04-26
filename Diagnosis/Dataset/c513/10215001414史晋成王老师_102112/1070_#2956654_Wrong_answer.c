#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int solve(int n)
{ int i;
  if(n==1) {i=2; return i;}
  else if (n==2) {i=4; return i;}
 else if (n==3) {i=7; return i;}
 else return (solve(n-1)+solve(n-1)-solve(n-3));
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