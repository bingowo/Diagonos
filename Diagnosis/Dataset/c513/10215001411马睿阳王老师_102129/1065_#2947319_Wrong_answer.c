#include<stdio.h>

int main()
{int a,n,m,x,t,d;
 scanf("%d%d%d",&a,&n,&m);
 int u[25],v[25],su[25],sv[25],i;
 for(i=3;i<=n;i++)
 {u[1]=1,u[2]=0;
  u[i]=u[i-1]+u[i-2];
 }
 for(i=3;i<=n;i++)
 {v[1]=0,v[2]=1;
  v[i]=v[i-1]+v[i-2];
 }
 for(i=3;i<=n;i++)
 {sv[1]=0,sv[2]=0;
  sv[i]=sv[i-1]+v[i]-v[i-1];
 }
 for(i=3;i<=n;i++)
 {su[1]=1,su[2]=1;
  su[i]=su[i-1]+v[i-1]-v[i-2];
 }
 t=(m-su[n-1]*a)/sv[n-1];
 d=su[x]*a+sv[x]*t;
 printf("%d",d);
 return 0;
}
