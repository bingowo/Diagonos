#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int pow(int x)
{
	if(x==0) return 1;
	long long ans=1;
	int i;
	for(i=0;i<x;i++) ans*=3;
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	char A[100];
	for(i=0;i<n;i++)
	{
		A[100]='0';
		scanf("%s",A);
		int k=strlen(A);
		int m=0;
		int s=k-1;
		int l=0;
		long long ans=0;
		while(l<k)
		{
			if(A[s]=='-') m=-1;
			else if(A[s]=='0') m=0;
			else if(A[s]=='1') m=1;
			ans+=m*pow(l);
			l++;s--;
		}
		printf("case #%d:\n%lld\n",i,ans);
	}
	return 0;
 } 