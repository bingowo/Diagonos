#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		unsigned long long x;
		int j=0;
		int a[1000];
		scanf("%d",&x);
		while(x!=0)
		{
			a[j]=x%2333;
			x/=2333;
			j++;
		}
		for(j--;j>=1;j--)printf("%d ",a[j]);
		printf("%d\n",a[0]);
	}
	return 0;
}