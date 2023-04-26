#include <stdio.h>
#include <string.h>
char s[1000] = {0};
int main(void)
{
	scanf("%s",s);
	printf("0001");
	int len = strlen(s);
	int x = len;
	int res[10] = {0};
	for(int i=0;i<10;i++)
	{
		if(x&1) res[i] = 1;
		x = x>>1;
	}
	for(int i=9;i>=0;i--) printf("%d",res[i]);
	for(int i=0;i+3<=len;i=i+3)
	{
		memset(res,0,sizeof(res));
		int tot = (s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
		for(int j=0;j<10;j++)
		{
			if(tot&1) res[j] = 1;
			tot = tot>>1;
		}
		for(int j=9;j>=0;j--) printf("%d",res[j]);
	}
	memset(res,0,sizeof(res));
	int lt = len%3;
	if(lt==1)
	{
		int tot = s[len-1]-'0';
		for(int i=0;i<4;i++)
		{
			if(tot&1) res[i] = 1;
			tot = tot>>1;
		}
		for(int i=3;i>=0;i--) printf("%d",res[i]);
	}
	else if(lt==2)
	{
		int tot = (s[len-2]-'0')*10 + (s[len-1]-'0');
		for(int i=0;i<7;i++)
		{
			if(tot&1) res[i] = 1;
			tot = tot>>1;
		}
		for(int i=6;i>=0;i--) printf("%d",res[i]);
	}
	return 0;
}