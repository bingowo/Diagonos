#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int n;
char s[100010][111] = {0};
char uni[100010][111] = {0};
int cnt[100010][111] = {0};
int sum[111] = {0};
int main(void)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	for(int i=0;i<n;i++)
	{
		int len = strlen(s[i]);
		int idx = 0;
		uni[i][idx++] = s[i][0];
		for(int j=1;j<len;j++) 
			if(s[i][j]!=s[i][j-1]) uni[i][idx++] = s[i][j];
		uni[i][idx] = '\0';
		//printf("%s\n",uni[i]);
	}
	int flag = 1;
	for(int i=1;i<n;i++)
	{
		if(strlen(uni[i])!=strlen(uni[i-1]))
		{
			flag = 0;
			break;
		}
		int f = 0;
		for(int j=0;j<strlen(uni[i]);j++)
		{
			if(uni[i][j]!=uni[i-1][j])
			{
				f = 1;
				break;
			}
		}
		if(f) 
		{
			flag = 0;
			break;
		}
	}
	if(!flag) 
	{
		printf("-1");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		int len = strlen(s[i]);
		int pos = 1;
		int idx = 0;
		cnt[i][idx] = 1;
		while(pos<len)
		{
			if(s[i][pos]==s[i][pos-1])
			{
				cnt[i][idx]++;
				pos++;
			}
			else
			{
				idx++;
				cnt[i][idx]++;
				pos++;
			}
		}
	}
	int len = strlen(uni[0]);
	for(int j=0;j<len;j++)
	{
		for(int i=0;i<n;i++)
			sum[j]+=cnt[i][j];
		sum[j] /= n;
	}
	int res = 0;
	for(int j=0;j<len;j++)
	{
		for(int i=0;i<n;i++)
			res += abs(sum[j]-cnt[i][j]);
	}
	printf("%d",res);
	return 0;
} 