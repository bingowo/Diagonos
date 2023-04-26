#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef unsigned long long ULL;
ULL ans[75];
int main()
{
	ans[0]=0;ans[1]=ans[2]=1;
	for(int i=3;i<=74;i++)ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		int x;scanf("%d",&x);
		printf("case #%d:\n",ct++);
		printf("%llu\n",ans[x]);
	}
	return 0;
}