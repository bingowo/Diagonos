#include<stdio.h>
#include<string.h>
int main()
{
	int Roma[128]={0};
	Roma['I']=1;Roma['V']=5;Roma['X']=10;Roma['L']=50;Roma['C']=100;Roma['D']=500;Roma['M']=1000;
	char s[51];scanf("%s",s);
	long long ans=0,flag=1,data[50];
	int cnt=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='(')flag*=1000;
		else if(s[i]==')')flag/=1000;
		else data[cnt++]=Roma[s[i]]*flag;
	}
	int total=cnt;
	for(cnt=0;cnt<total-1;cnt++)if(data[cnt]<data[cnt+1])data[cnt]*=-1;
	for(cnt=0;cnt<total;cnt++)ans+=data[cnt];
	printf("%lld",ans);
	return 0;
}