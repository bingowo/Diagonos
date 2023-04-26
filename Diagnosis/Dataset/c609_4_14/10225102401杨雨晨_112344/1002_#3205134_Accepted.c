#include <stdio.h>
#define M 32
int main()
{	int t,m,p,n,i,q;
	int a[M],b[M];
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{	scanf("%d",&m);
		for (p=0;m/2!=0;m=m/2,p++)
		{a[p]=m%2;}
		a[p]=m;
		for(q=0;p>=0;q++)
		{m=1;n=1;
		while(a[p]!=a[--p]&&p>=0){m++;}
		 while(a[p]==a[p-1]&&p>=0){p--;}
		 while(a[p]!=a[--p]&&p>=0){n++;}
		if (m>n){n=m;}
		b[q]=n;
		if (q>0&&b[q]<b[q-1]){n=b[q-1];}
		}
		
		printf("case #%d:\n",i);
		printf("%d\n",n);
	}
}
	