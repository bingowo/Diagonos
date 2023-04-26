#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int a[101]={0},k,n;
	scanf("%d%d",&k,&n); 
	if(k>2)
	{
		for(int i=2;i<=k+1;i++)
		{
			a[i]=(int)pow(2,i-2);
		}
	}
	for(int i=k+2;i<=n;i++)
	{
		a[i]=a[i-1]*2-a[i-k-1];
	}
	printf("%d",a[n-1]);
}