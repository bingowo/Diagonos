#include <stdio.h>
#include <stdlib.h>
int haozi(int n,int p,int m,int t,int sum)
{if(p==n)
{p=p-1;m--;
if(m==0&&p!=t) return sum;
if(m==0&&p==t) {sum+=1;return sum;}
if(m>0) sum=haozi(n,p,m,t,sum);}
if(p==1)
{p=2;m--;
if(m==0&&p!=t) return sum;
if(m==0&&p==t) {sum+=1;return sum;}
if(m>0) sum=haozi(n,p,m,t,sum);}

if(p!=n&&p!=1)
{for(int i=1;i>=-3;i-=4)
{p=p+i;m--;
if(m==0&&p!=t) return sum;
if(m==0&&p==t) {sum+=1;return sum;}
if(m>0) sum=haozi(n,p,m,t,sum);
m++;}
}
}

int main()
{int j,n,p,m,t;
scanf("%d",&j);
for(int i=0;i<j;i++)
{scanf("%d%d%d%d",&n,&p,&m,&t);
printf("%d",haozi(n,p,m,t,0));
printf("\n");
}
}
