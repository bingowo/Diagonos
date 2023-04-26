#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void divide(int* ans,int*tail,int num)
{
	int t=0;
	for(int i=0;i<*tail;i++)
	{
		t=ans[i]%8;
		ans[i]=ans[i]/8;
		ans[i+1]+=t*10;
		while(ans[*tail]!=0)
			(*tail)++;
	}
	ans[0]+=num;
	while(ans[*tail]!=0)
		(*tail)++;
}
int main()
{
	long long t;
	scanf("%lld",&t);
	for(long long m=0;m<t;m++)
	{
		char s[50];
		int ans[150],tail=0;
		for(int i=0;i<150;i++)ans[i]=0;
		scanf("%s",s);
		int i=strlen(s)-1;
		for(;s[i]!='.';i--)
		{
			divide(ans,&tail,s[i]-'0');
		}
		divide(ans,&tail,0);
		printf("case #%d:\n0.",m);
		for(int i=1;i<tail;i++)
			printf("%d",ans[i]);
		printf("\n"); 
	}
	return 0;
}