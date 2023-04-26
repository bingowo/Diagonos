#include<stdio.h>

int f(int n)
{
  if(n==1) return 1;
  else if(n==2) return 2;
  else if(n==3) return 4;
  else if(n==4) return 8;
  else return f(n-1)+f(n-2)+f(n-3)+f(n-4);
}
int main()
{int T,i;
 int n,m;
 scanf("%d",&T);
 for(i=0,m=0,n=0;i<T;i++)
{
 scanf("%d",&n);
 m=f(n);
 printf("case #%d:\n",i);
 printf("%d\n",n);
}
return 0;
}

