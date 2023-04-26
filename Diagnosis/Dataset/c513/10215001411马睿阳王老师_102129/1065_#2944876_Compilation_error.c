#include<stdio.h>
int a,y;

int f(int n)//上车人数
{ if(n==1) return a;
  else if(n==2) return y;
  else return f(n-1)+f(n-2);
}

int g(int n)//下车人数
{ if(n==1) return 0;
  else return f(n-1);
}

int h(int n)//现有人数
{ if(n==1) return a;
  else if(n==2) return a;
  else return f(n-2);
}
int main()
{int n,m,x,v;
 scanf("%d%d%d",&a,&n,&m);
 g(n)=m;
 v=h(x);
 printf("%d",v);
 return 0;
}
