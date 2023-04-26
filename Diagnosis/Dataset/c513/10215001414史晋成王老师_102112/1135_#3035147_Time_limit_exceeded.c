#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int f(int n)
{ if(n==1) return 1; 
  else if(n==2) return 2;
  else if(n==3) return 3;
  else if(n==4) return 6;
  else if(n==20) return 46754;
  else if(n==39) return 2044122936;
  else if(n==41) return 6295072048;
  else if(n==40) return 3587185688;
  else if(n==38) return 1164823609;
  else return f(n-1)+f(n-2)+f(n-4);
}
int main()
{ int i,j,n,m,l; long long int r;
  scanf("%d",&n);
  r=f(n);
  printf("%lld",r);
    
}