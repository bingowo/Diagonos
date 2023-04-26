#include<stdio.h>

int u(int i)
{if(i==1) return 1;
 else if(i==2) return 0;
 else return u(i-1)+u(i-2);
}

int v(int i)
{if(i==1) return 0;
 else if(i==2) return 1;
 else return v(i-1)+v(i-2);
}

int su(int i)
{if(i==1) return 1;
 else if(i==2) return 2;
 else return su(i-1)+v(i-1)+v(i-2);
}

int sv(int i)
{if(i==1) return 0;
 else if(i==2) return 0;
 else return sv(i-1)+v(i)-v(i-1);
}


int main()
{int a,n,m,x,t,d;
 scanf("%d%d%d",&a,&n,&m);
 t=(m-su(n-1)*a)/su(n-1);
 d=su(x)*a+sv(x)*t;
 printf("%d",d);
 return 0;
}
