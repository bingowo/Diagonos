#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		long long n;
		scanf("%lld",&n);
		int a[1000]={0},k=0;
		while(n>0)
		{
			a[k]=n%2333;
			n/=2333;
			k++;
		}
		for(int i=k-1;i>0;i--) printf("%d ",a[i]);
		printf("%d\n",a[0]);
	}
	return 0;
}