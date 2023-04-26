#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int ct=0,T;scanf("%d",&T);
	char a[250];
	while(T--)
	{
		scanf("%s",a);
		int n=strlen(a);
		long long ans=0,x;
		for(int i=0;i<n;i++)
		{
			if(a[i]=='-')x=-1;
			else if(a[i]=='0')x=0;
			else x=1;
			ans=ans*3+x;
		}
		printf("case #%d:\n%lld\n",ct++,ans);
	}
	return 0;
}