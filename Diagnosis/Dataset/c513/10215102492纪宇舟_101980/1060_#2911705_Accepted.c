#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
	char s[105];scanf("%s",s);
	int n=strlen(s);
	int ans=0,flag=0,sum=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			if(flag==0&&s[i]=='0')continue;
			flag=1;sum++;
		}
		if(s[i]<'0'||s[i]>'9'||i==n-1)
		{
			if(sum>ans)ans=sum;
			flag=sum=0;
		}
	}
	printf("%d",ans);
	return 0;
} 