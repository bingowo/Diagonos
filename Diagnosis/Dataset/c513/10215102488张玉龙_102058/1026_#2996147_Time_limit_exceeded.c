#include<stdio.h>
int main() 
{
	int n,sum=0,a[100001],temp,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
		for(int j=0;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(a[k]<a[j])
				{
					temp=a[k];
					a[k]=a[j];
					a[j]=temp;
				}
			}
		}
	for(i=0;i<n;i+=2)
	{
		sum+=(a[i+1]-a[i]);
	}
	printf("%d",sum);
}