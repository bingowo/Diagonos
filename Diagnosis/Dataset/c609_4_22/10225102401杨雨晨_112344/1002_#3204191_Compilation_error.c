#include <stdio.h>
#define M 32
#define N 0
void f(int a,int r,char s[])
{int j=0;
while (a/r){f(a/r,r);}
s[j++]=a%r;
}
int main()
{	int t,m,p,n,i;
	int a[M];
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{	scanf("%d",&m);
		f(m,2,a[]);
		for(m=n=0;p>=0;)
		{while(a[p]!=a[--p]&&p>0){m++;}
		 while(a[p]==a[p-1]&&p>0){p--;}
		 while(a[p]!=a[--p]&&p>0){n++;}
		if (m>n)n=m;
		}
		printf("case #%d:\n",i);
		printf("%d\n",n);
	}}
  