#include<stdio.h>
int P(int n,int p,int m,int t)
{if(m>0)
{if(p==1)return P(n,2,m-1,t);
if(p==n) return P(n,n-1,m-1,t);
 else return P(n,p+1,m-1,t)+P(n,p-1,m-1,t);
}
else if(m==0&&p==t) return 1;
else return 0;
}
int main()
{int n,p,m,t,a,v,i;
scanf("%d",&a);
for(i=0;i<a;i++)
{scanf("%d%d%d%d",&n,&p,&m,&t);
v=P(n,p,m,t);
printf("%d\n",v);
}

}
