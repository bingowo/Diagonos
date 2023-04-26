#include<stdio.h>
#include<string.h>
long long int mod=1000000007; 
void func(char*s)
{
	int len=strlen(s);
	long long r=1;
	if(len==1)printf("1");
	else if(len==2)
	{
		if(s[0]==s[1])printf("1");
		else printf("4");
	}
	else
	
	if(s[0]!=s[1])r=2;
	for(int i=1;i<len-1;i++)
	{
		long long c=1;
		if(s[i]!=s[i-1])c++;
		if(s[i]!=s[i+1]&&s[i-1]!=s[i+1])c++;
		r=(r*c)%mod;//让每次的中间结果取模，避免大数 
	}
	if(s[len-1]!=s[len-2])r=(r*2)%mod;
	printf("%lld",r);
}
int main()
{
	char s[10001];
	scanf("%s",s);
	func(s);
}