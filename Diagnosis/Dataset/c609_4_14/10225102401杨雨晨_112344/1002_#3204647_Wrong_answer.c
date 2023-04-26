#include <stdio.h>
#define M 32
int main()
{	int t,m,p,n,i;
	int a[M];
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{	scanf("%d",&m);
		for (p=0;m/2!=0;m=m/2,p++)
		{a[p]=m%2;}
		a[p]=m;
		for(m=1,n=1;p>=0;)
		{while(a[p]!=a[--p]&&p>=0){m++;}
		 while(a[p]==a[p-1]&&p>=0){p--;}
		 while(a[p]!=a[--p]&&p>=0){n++;}
		if (m>n)n=m;
		}
		
		printf("case #%d:\n",i);
		printf("%d\n",n);
	}}
  