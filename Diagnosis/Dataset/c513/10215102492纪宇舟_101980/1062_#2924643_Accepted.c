#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
	int ct=0,T;scanf("%d",&T);
	long long ans[51];
	ans[0]=1;
	for(int i=1;i<=50;i++)
	{
		ans[i]=ans[i-1];
		if(i-2>=0)ans[i]+=ans[i-2];
		if(i-3>=0)ans[i]+=ans[i-3];
		if(i-4>=0)ans[i]+=ans[i-4];
	}
	while(T--)
	{
		int x;scanf("%d",&x);
		printf("case #%d:\n",ct++);
		printf("%lld\n",ans[x]);
	}
	return 0;
}