#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int cnt=0;cnt<n;cnt++)
	{
		char s[1005];
		scanf("%s",s);
		int j=strlen(s),ans=0;
		while(j--)
		{
			if(s[j]=='1')ans+=pow(3,strlen(s)-j-1);
			if(s[j]=='-')ans-=pow(3,strlen(s)-j-1);
		}
		if(s[j]=='1')ans+=pow(3,j);
		if(s[j]=='-')ans-=pow(3,j);
		printf("case #%d:\n%d\n",cnt,ans);
	}
	return 0;
	
}