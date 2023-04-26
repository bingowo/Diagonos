#include<stdio.h>
#include<string.h>
int main()
{
	int t,cnt;
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;i++)
	{
		cnt=1;
		char s[501]={0};
		gets(s);
		for(int j=0;j<strlen(s);j++)
		{
			if(s[j+1]==s[j])
			{
				cnt++;
				if(cnt==255)
				{
					printf("%d%c",cnt,s[j]);
					cnt=1;
					j++;
				}
			}
			else
			{
				printf("%d%c",cnt,s[j]);
				cnt=1;
			}
		}
		printf("\n");
	}
	return 0;
}