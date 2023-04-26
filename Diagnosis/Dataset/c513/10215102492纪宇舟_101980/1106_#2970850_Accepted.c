#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
#define mod 1000000007
typedef long long LL;
LL yes[1005];
int main()
{
	char s[1005];
	scanf("%s",s);
	int n=strlen(s);
	if(n==1)
	{
		printf("1");return 0;
	}
	if(s[0]==s[1])yes[0]=1;
	else yes[0]=2;
	for(int i=1;i<n;i++)
	{
		if(i==n-1)
		{
			if(s[i]==s[i-1])yes[i]=yes[i-1];
			else yes[i]=yes[i-1]*2%mod;
			break;
		}
		if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
		yes[i]=yes[i-1]*3%mod;
		else if(s[i]==s[i-1]&&s[i]==s[i+1])
		yes[i]=yes[i-1];
		else yes[i]=yes[i-1]*2%mod;
	}
	printf("%lld",yes[n-1]);
	return 0;
}