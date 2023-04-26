#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int T,ct=0;scanf("%d",&T);
	char ipt[55];
	while(T--)
	{
		scanf("%s",ipt);
		int n=strlen(ipt);
		double ans=0,x=1.0/8.0;
		for(int i=2;i<n;i++)
		{
			ans+=((double)(ipt[i]-'0'))*x;
			x/=8.0;
		}
		printf("case #%d:\n",ct++);
		printf("0."); 
		int cnt=0;
		while(ans>0&&cnt<3*(n-2))
		{
			ans*=10.0;
			int x=ans;
			printf("%d",x);
			ans-=x;cnt++;
		}
		printf("\n");
	} 
	return 0;
} 