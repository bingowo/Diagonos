#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<malloc.h>
int main()
{
	char s[105];
	int sum,num,sig,flag;
	int m1[105],m2[105],ans[105];
	while(scanf("%s",s)!=EOF)
	{
		int n1=0,n2=0;
		memset(m1,0,sizeof(m1));
		memset(m2,0,sizeof(m2));
		memset(ans,0,sizeof(ans));
		int n=strlen(s);
		sum=num=flag=0;sig=1;
		for(int i=0;i<n;i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				if(flag)num=num*10+s[i]-'0';
				else sum=sum*10+s[i]-'0';
			}
			if(s[i]=='x')flag=1;
			if(s[i]=='+'||s[i]=='-'||i==n-1)
			{
				if(flag)
				{
					if(sum==0)sum=1;
					if(num==0)num=1;
					m1[num]+=sum*sig;//printf("%d %d %d\n",sum,num,m1[1]);
				}
				else m1[0]+=sum*sig;
				if(num>n1)n1=num;
				sum=num=flag=0;
				if(s[i]=='-')sig=-1;
				else sig=1;
			}
		}
		scanf("%s",s);n=strlen(s);
		sum=num=flag=0;sig=1;
		for(int i=0;i<n;i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				if(flag)num=num*10+s[i]-'0';
				else sum=sum*10+s[i]-'0';
			}
			if(s[i]=='x')flag=1;
			if(s[i]=='+'||s[i]=='-'||i==n-1)
			{
				if(flag)
				{
					if(sum==0)sum=1;
					if(num==0)num=1;
					m2[num]+=sum*sig;//printf("%d %d %d\n",sum,num,m2[1]);
				}
				else m2[0]+=sum*sig;
				if(num>n2)n2=num;
				sum=num=flag=0;
				if(s[i]=='-')sig=-1;
				else sig=1;
			}
		}
		for(int i=0;i<=n1;i++)
		for(int j=0;j<=n2;j++)
		{
			ans[i+j]+=m1[i]*m2[j];
			//printf("%d %d %d\n",i,j,ans[i+j]);
		}
		int out=0;
		for(int i=105;i>=0;i--)
		if(ans[i]!=0)
		{
			out=1;printf("%d ",ans[i]);
		}
		if(out==0)printf("0");
		printf("\n");
	}
	return 0;
}