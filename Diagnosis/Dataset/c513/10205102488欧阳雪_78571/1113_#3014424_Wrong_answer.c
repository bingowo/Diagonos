#include<stdio.h>
int main()
{
	int k,n;
	scanf("%d%d",&k,&n);
	long long int a[500]={0};
	a[0]=0,a[1]=1;
	for(int i=2;i<n;i++)
	{
		if(k>=i+1)
		{
			for(int t=0;t<i;t++)
			{
				a[i]+=a[t];
			}
		}
		else{
			int j=i-1;
			for(int m=0;m<k;m++)
			{
				a[i]+=a[j];
				j--;
			}
		}
	}
	printf("%lld",a[n-1]);
 } 