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
		for(;p>=1;)
		{m=n=1;
		    while(a[p]!=a[--p]&&p>=1){m++;}
		 while(a[p]==a[p-1]&&p>=1){p--;}
		 while(a[p]!=a[--p]&&p>=1){n++;}
		if (m>n)n=m;
		}
		
		printf("case #%d:\n",i);
		printf("%d\n",n);
	}}