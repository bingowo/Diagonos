#include <stdio.h>
#include <stdlib.h>

#define N 95
void mul(int *result,int a,int n)
{
	int i,carry=0,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
		
			int t=result[j]*a+carry;
			result[j]=t%10;
			carry=t/10;
		}
	}
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int result[100]={1};
		int a,n;
		scanf("%d %d",&a,&n);
		mul(result,a,n);
		int k;
		int m;
		printf("case #%d:\n",i);
		if(n==0) printf("1");
		else
		{
		
			for(m=n-1;result[m]==0;m--);
			for(k=m;k>=0;k--) printf("%d",result[k]);
		}
		printf("\n");
	}
	return 0;
}