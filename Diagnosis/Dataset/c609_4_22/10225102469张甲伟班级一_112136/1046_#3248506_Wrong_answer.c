#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int sum[100005][105],len[100005],n;
char s[100005][105],s1[100005][105];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]+1);
	for(int j=0;j<n;j++)
	{
		int length=strlen(s[j]+1);
		for(int i=1;i<=length;i++)
		{
			if(s[i]!=s[i-1])
				s1[j][++len[j]]=s[j][i];
			sum[i][len[j]]++;
		}
	}
	for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;i++)
			{
				if(strcmp(s1[i],s1[j])!=0)
				{
					puts("-1");
					return 0;
				}
			}
		}
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=len[i];j++)
			ans+=abs(sum[i][j]-sum[i-1][j]);
	}
	printf("%d",ans);
	return 0;
}