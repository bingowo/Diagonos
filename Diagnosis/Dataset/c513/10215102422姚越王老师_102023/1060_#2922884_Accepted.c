#include<stdio.h>
#include<string.h>
int Max(int a,int b)
{
	if(a>b)return a;
	else return b;
}
int main()
{
	char s[110];
	scanf("%s",s);
	int i,j,k,flag=0,cnt=0,max=-1;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]>='1'&&s[i]<='9'&&!flag)
		{
			flag=1;
			cnt++;
		}
		else if(s[i]>='0'&&s[i]<='9'&&flag)
		{
			cnt++;
		}
		else
		{
			flag=0;
			max=Max(max,cnt);
			cnt=0;
		}
	}
	if(cnt)max=Max(max,cnt);
	printf("%d",max);
	return 0;
}