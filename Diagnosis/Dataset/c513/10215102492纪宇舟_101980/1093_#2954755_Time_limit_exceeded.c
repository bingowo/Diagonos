#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char s[105];
int num[1005];
int main()
{
	scanf("%s",s);
	int cnt=0,n=strlen(s);
	for(int i=n-1;i>=0;i--)num[++cnt]=s[i]-'0';
	num[1]++;
	for(int i=1;i<=cnt;i++)
	if(num[i]==10)
	{
		num[i]=0;
		if(i+1>cnt)num[++cnt]=0;
		num[i+1]++;
	}
	while(1)
	{
		int j=cnt,sum=0,flag=0;
		for(int i=cnt;i>=1;i--)
		{
			sum+=num[i];
			if(num[i]==9)
			{
				if(i+1>cnt)num[++cnt]=0;
				num[i+1]++;
				for(int j=i;j>=1;j--)num[j]=0;
				flag=1;break;
			}
		}
		if(flag)continue;
		if(sum%9!=0)break;
	}
	for(int i=cnt;i>=1;i--)printf("%d",num[i]);
	return 0;
} 