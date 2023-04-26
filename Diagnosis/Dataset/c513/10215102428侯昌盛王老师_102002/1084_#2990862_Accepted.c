#include <stdio.h>
#include <math.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int a[31]={0};
	
		a[0]=2;
		int k=1,carry=0,t;
		for(k;k<n;k++)
		{
			int m=0;
			for(m;m<=k;m++)
			{
				t=a[m]*2+carry;
				a[m]=t%10;
				carry=t/10;
			}
		}
		int j=0;
		printf("case #%d:\n",i);
		if(n==0) printf("1\n");
		else{
		
			for(n;a[n]==0;n--);
			int e;
			for(e=n;e>=0;e--) printf("%d",a[e]);
			printf("\n");
		}
	}
}