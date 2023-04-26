#include <stdio.h>
#include <string.h>
int main()
{
	char s[1001];
	int len,i;
	long long sum;
	scanf("%s",s);
	len=strlen(s);
	if(len==1)
	{
		sum=1;
		goto ans;
	}
	if(s[0]!=s[1]) sum=2;
	else sum=1;
	
	for(i=1;i<len-1;i++)
	{
		if(sum>1000000007) sum%=1000000007;
		if(s[i]!=s[i-1]&&s[i]!=s[i+1])
		{
			if(s[i-1]!=s[i+1]) sum*=3;
			else if(s[i-1]==s[i+1]) sum*=2;
		}
		else if(s[i]==s[i-1]&&s[i]==s[i+1]) sum*=1;
		else
		{
			sum*=2;
		}
	}
	if(sum>1000000007) sum%=1000000007;
	if(s[len-1]!=s[len-2]) sum*=2;
	sum%=1000000007;
	ans:printf("%lld\n",sum);
	return 0;
}