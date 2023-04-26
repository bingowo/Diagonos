#include<stdio.h>
#include<stdlib.h>
long long int solve(long long int x,long long int y)
{ long long int n,m;
   
   if (x==y) return 4*x;
   else if(y==1) return 4*y*x/y;
   else if (y==100) return 4*y*x/y;
   else if (x>y) return solve(x-y,y)+4*y;
   else if (x<y) return solve(y-x,x)+4*x;
}
int main()
{ long long int x,y,n,i,j;
scanf("%lld %lld",&x,&y);
n=solve(x,y);
printf("%lld",n);
}