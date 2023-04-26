#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gc(int n,int m)
{
	int i;
	int ans;
	for(i=n;i>=2;i--)
	{
		if((n%i==0)&&(m%i==0)) return i;
	}
}

int main()
{
	int n;
	scanf("%d\n",&n);
	int i;
	for(i=0;i<n;i++)
	{
		char A[200];
		gets(A);
		int l=strlen(A);
		int j;
		int ans=0;
		for(j=0;j<l;j++)
		{
			for(int k=0;k<8;k++)
			{
				if((A[j]>>k)&1==1) ans++;
			}
			
		}
		int m=8*l;
		int k=gc(ans,m);
		int a,b;
		a=ans/k;b=m/k;
		printf("%d/%d\n",a,b);
		
	}
	return 0;
}