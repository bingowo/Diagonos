#include<stdio.h>

int f(int n)
{
  if(n==1) return 1;
  else if(n==2) return 2;
  else if(n==3) return 4;
  else return f(n-1)+f(n-2)+f(n-3);
}
int main()
{int T,i,m=0;
 int s[12],b[12];
 scanf("%d",&T);
 for(i=0;i<T;i++)
 {scanf("%d\n",&s[i]);}
 for(i=0;i<T;i++)
 {b[i]=f(s[i]);
 printf("case #%d:\n",i);
 printf("%d\n",b[i]);
 }
 return 0;
}

