#include <stdio.h>
#define M 32
#define N 0
void f(int m,int r,int s[])
{int j=0;
while (m/r){f(m/r,r,s);}
s[j++]=m%r;
}
int main()
{	int t,m,p,n,i;
	int a[M];
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{	scanf("%d",&m);
		f(m,2,a);
		for(m=n=0;p>=0;)
		{while(a[p]!=a[--p]&&p>0){m++;}
		 while(a[p]==a[p-1]&&p>0){p--;}
		 while(a[p]!=a[--p]&&p>0){n++;}
		if (m>n)n=m;
		if(m=n=0)n=1;
		}
		printf("case #%d:\n",i);
		printf("%d\n",n);
	}}
  