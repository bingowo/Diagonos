#include<stdio.h>
#include<string.h>
#define MAX 10000
int main()
{
	char s[MAX]={0};
	scanf("%s",s);
	int f1=0,f2=0;//f1标记上一个数字下一位，f2标记目前数字的首位 
	int i=0;
	while(i<strlen(s))
	{
		while(s[i]>='a'&&s[i]<='z')
		{
			printf("%c",s[i]);
			i++;
		}
		f2=i;
		int cnt=0;
		while(s[i]>='0'&&s[i]<='9'&&i<strlen(s))
		{
			cnt*=10;
			cnt+=(s[i]-'0');
			i++;
		}
		if(cnt>1)
		{
			for(int k=0;k<cnt-1;k++)
			{
				int z=f1;
				for(z;z<f2;z++)
				{
					printf("%c",s[z]);
				}
			}
		}
		f1=i;
	}
}