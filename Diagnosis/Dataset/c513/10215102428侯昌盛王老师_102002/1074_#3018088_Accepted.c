#include <stdio.h>
#include <string.h>

int main()
{
	int t,e;
	long long mod=1e9+7;
	scanf("%d",&t);
	for(e=0;e<t;e++)
	{
		int i=0;
		char s[101];
		scanf("%s",s);
		int a[101]={0},len;
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			a[i]=s[i]-'0';
		}
		int dp[101][210]={0};
		dp[0][0]=1;
		int rem=0,j;
		long long temp=0;
		for(i=0;i<len;i++)
		{
			for(rem=0;rem<210;rem++)
			{
				temp=0;
				for(j=i+1;j<=len;j++)
				{
					temp*=10;
					temp+=a[j-1];
					temp%=210;
					dp[j][(rem+temp)%210]+=dp[i][rem];
					dp[j][(rem+temp)%210]%=mod;
					dp[j][(rem-temp+210)%210]+=dp[i][rem];
					dp[j][(rem-temp+210)%210]%=mod;
				}
			}
		}
		long long ans=0;
		for(i=0;i<210;i++)
		{
			if(!(i%2)||!(i%3)||!(i%5)||!(i%7))
			{
				ans+=dp[len][i];
				ans%=mod;
			}
		}
		printf("%d\n",ans*((mod+1)/2)%mod);
	}
	return 0;
	
}