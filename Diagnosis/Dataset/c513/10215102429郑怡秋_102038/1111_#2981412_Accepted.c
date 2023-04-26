#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void cor(char ind[],int a[])
{
	int l=strlen(ind);
	int i=0;
	int sign=1;
	if(ind[i]=='-') sign=-1;
	while(i<=l)
	{
		int an=0;
		while(isdigit(ind[i]))
		{
			an=an*10+ind[i++]-'0';
		}
		if(isalpha(ind[i]))
		{
			if(an==0) an=1;
			if(ind[i+1]=='^') a[ind[i+2]-'0']=an*sign;
			else a[1]=an*sign;
		}
		if(ind[i]=='-')
		{
			sign=-1;
		}
		else if(ind[i]=='+')
		{
			sign=1;
		}
		if(i==l&&isdigit(ind[i-1])&&(ind[i-2]!='^'||ind[i-2]!='^'))
		{
			a[0]=an*sign;
		}
		i++;
	}

}
int pingf(int a,int n)
{
	int ans=1;
	for(int i=0;i<n;i++) ans*=a;
	return ans;
}
int cul(int a[],int n)
{
	int ans=0;
	for(int i=0;i<4;i++)
	{
		if(a[i]!=0)
		{
			ans+=a[i]*pingf(n,i);//printf("%d %d %d\n",a[i],pingf(n,i),ans);
		}
	}
	return ans;
}
int main()
{
	char ans[50][50];
	for(int i=0;i<41;i++)
	{
		for(int j=0;j<41;j++)
		{
			if(i!=0&&j==20) ans[i][j]='|';
			else if(i==20&&j!=40) ans[i][j]='-';
			else ans[i][j]='.';
		}
		ans[20][20]='+';
		ans[20][40]='>';
		ans[0][20]='^';
		ans[i][41]='\0';
	}
	
	char ind[100];

	for(int i=0;i<5;i++) getchar();
	while(scanf("%s",ind)!=EOF)
	{
		int a[100]={0};	
		cor(ind,a);
//		printf("%s\n",ind);
//		for(int i=0;i<20;i++) printf("%d",a[i]);
//		printf("\n");
	char ans[50][50];
	for(int i=0;i<41;i++)
	{
		for(int j=0;j<41;j++)
		{
			if(i!=0&&j==20) ans[i][j]='|';
			else if(i==20&&j!=40) ans[i][j]='-';
			else ans[i][j]='.';
		}
		ans[20][20]='+';
		ans[20][40]='>';
		ans[0][20]='^';
		ans[i][41]='\0';
	}
	
		for(int i=0;i<41;i++)
		{
			int tump;
			tump=cul(a,i-20);
			if(tump<=20&&tump>=-20)
			{
				ans[20-tump][i]='*';
			}
		}
		
		for(int i=0;i<41;i++) printf("%s\n",ans[i]);
		printf("\n");
		//printf("%d\n",cul(a,0));
		if(getchar()==EOF) break;
		for(int i=0;i<4;i++) getchar();
	}
	return 0;
}