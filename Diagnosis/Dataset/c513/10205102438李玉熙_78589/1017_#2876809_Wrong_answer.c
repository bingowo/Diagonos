#include<stdio.h>
int main()
{
	int Roma[128]={0};
	Roma['I']=1;
	Roma['X']=10;
	Roma['V']=5;
	Roma['L']=50;
	Roma['C']=100;
    Roma['D']=500;
    Roma['M']=1000;
    long long data[100];
    int cnt=0;
    int flag=1;
    char s[1000];
	scanf("%s",&s); 
    for(int i=0;s[i];i++)
    {
    	switch(s[i])
    	{
    		case '(': flag=flag*1000;break;
    		case ')': flag=flag/1000;break;
    		default: data[cnt++]=Roma[s[i]]*flag;break;
		}
	}
	long long ans=0;
	for(int i=0;i<cnt-1;i++)
	{
		if(data[i]<data[i+1])
		{
			ans-=data[i];
		}
		else ans+=data[i];
	}
	ans+=data[cnt-1];
	printf("%lld",ans);
}