#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int ct=0,T;scanf("%d",&T);
	char a[62];
	int n;
	int maps[258];
	long long ans,x;
	while(T--)
	{
		scanf("%s",a);
		n=strlen(a);x=0;
		if(n==1){printf("0\n");continue;}
		memset(maps,0,sizeof(maps));
		int sig=-1;
		for(int i=0;i<n;i++)
		{
			if(sig==-1&&a[i]!=a[0])sig=i;
			if(maps[a[i]]==0&&a[i]!=a[sig])maps[a[i]]=++x;
		}
		ans=0;++x;
		for(int i=0;i<n;i++)
		{
			ans=ans*x+(long long)maps[a[i]];
			//printf("%lld ",maps[a[i]]);
		}
		//printf("\n");
		printf("case #%d:\n%lld\n",ct++,ans);
	}
	return 0;
}