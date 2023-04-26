#include <stdio.h>
#include <stdlib.h>
int haozi(int n,int p,int m,int t)
{if(p==t&&m==0) return 0;
if(p!=t&&m==0) return 1;
if(p==1) return haozi(n,p+1,m-1,t);
if(p==n) return haozi(n,p-1,m-1,t);
return haozi(n,p-1,m-1,t)+haozi(n,p+1,m-1,t);

}


int main()
{int j,n,p,m,t;
scanf("%d",&j);
for(int i=0;i<j;i++)
{scanf("%d%d%d%d",&n,&p,&m,&t);
printf("%d",haozi(n,p,m,t));
printf("\n");
}
}
