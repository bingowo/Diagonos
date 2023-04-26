#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d",&T);
	char A[100];
	int i;
	for(i=0;i<T;i++)
	{
		scanf("%s",A);
		char* p=A;
		int a[128];
		int digit=0,N=1;
		for(int j=0;j<128;j++) a[j]=-1;
		a[*p]=1;
		while(*++p)
		{
			if(a[*p]==-1)
			{
				a[*p]=digit;digit=digit?digit+1:2;N++;
			}
		}
		
		long long ans=0;
		p=A;while(*p) ans=ans*N+a[*p++];
		printf("case #%d:\n%lld\n",i,ans);
	}
	return 0;
}