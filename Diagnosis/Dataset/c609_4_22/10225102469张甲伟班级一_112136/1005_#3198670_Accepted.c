#include<stdio.h>
int T,n,t,cnt;
long long ans;
char a[100000];
int main()
{
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%s",a);
		ans=0;
		for(int j=0;a[j]!='\0';j++)
		{
			int t;
			if(a[j]=='1')
				t=1;
			if(a[j]=='0')
				t=0;
			if(a[j]=='-')
				t=-1;
			ans=ans*3+t;
		}
		printf("case #%d:\n",i);
		printf("%lld\n",ans);
	}
	return 0;
 } 