#include<stdio.h>
void mul(int result[],int a,int n)
{
	int i,j,carry=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<100;j++)
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
		scanf("%d%d",&a,&n);
		mul(result,a,n);
		int k,m;
		printf("case #%d:\n",i);
		if(n==0)
			printf("1");
		else
		{
			for(m=n;result[m]==0;m--);
			for(k=m;k>=0;k--)
			printf("%d",result[k]);
		}
		printf("\n");
	}
	return 0;
}