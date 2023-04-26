#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
int bin[33];
int MAX(int a,int b)
{
	if(a>b)return a;
	return b;
}
int main()
{
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		int n,cnt=0;
		scanf("%d",&n);
		while(n)
		{
			bin[++cnt]=n%2;n/=2;
		}
		bin[cnt+1]=0;
		int ans=1,sum=1;
		for(int i=1;i<cnt;i++)
		if(bin[i]==bin[i+1])
		{
			ans=MAX(ans,sum);sum=1;
		}
		else sum++;
		ans=MAX(ans,sum);
		printf("case #%d:\n%lld\n",ct++,ans);
	}
	return 0;
}