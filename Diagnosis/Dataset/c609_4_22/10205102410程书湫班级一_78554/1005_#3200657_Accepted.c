#include <stdlib.h>
#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	int a[1000]={0};
	a['0']=0;
	a['1']=1;
	a['-']=-1;
	for(int cas=0;cas<T;cas++)
	{
		char s[1000];
		scanf("%s",s);
		char *p=s;
		long long N=0;
		while(*p) N=N*3+a[*p++];
		printf("case #%d:\n%lld\n",cas,N);
	}
	return 0;
}