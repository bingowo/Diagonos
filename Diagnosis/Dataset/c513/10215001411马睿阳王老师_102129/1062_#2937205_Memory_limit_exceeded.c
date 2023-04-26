#include<stdio.h>

int f(int n)
{
  if(n==1) return 1;
  else if(n==2) return 2;
  else if(n==2) return 3;
  else return f(n-1)+f(n-2)+f(n-3);
}
int main()
{int T,i,m=0;
 int n;
 scanf("%d",&T);
 for(i=0;i<T;i++)
 {scanf("%d\n",&n);
 printf("case #%d:",i);
 m=f(n);
 printf("%d",m);
 }
 return 0;
}

