#include<stdio.h>
#include<string.h>
int main()
{
	int total;
	scanf("%d",&total);
	char s[61];
	int a[128];
	for(int cnt=0;cnt<total;cnt++)
	{
		scanf("%s",s);
		for(int i=0;i<128;i++)a[i]=-1;
		a[s[0]]=1;
		int number=0,N=1;
		unsigned long long int ans=0;
		for(int i=1;i<strlen(s);i++)
		{
			if(a[s[i]]==-1&&number==0)
			{
				a[s[i]]=number;
				number=2;
			}
			else if(a[s[i]]==-1)a[s[i]]=number++;
			N++;
		}
		if(N==1)N=2;
		for(int i=0;i<strlen(s);i++)ans=ans*N+a[s[i]];
		printf("case #%c:\n%ull\n",cnt+48,ans);
	}
}