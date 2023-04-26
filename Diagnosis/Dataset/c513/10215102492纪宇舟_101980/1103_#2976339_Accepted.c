 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int a[256];
int main()
{
	int tar,n,sum,sum1,sum2,sig;
	char s[15],chr[1005];
	memset(a,0,sizeof(a));
	while(scanf("%s",s)!=EOF)
	{
		scanf("%s",chr);
		n=strlen(chr);sum=0;sig=1;
		if(s[0]=='I')
		{
			tar=chr[0];
			for(int i=3;i<n;i++)
			{
				if(chr[i]=='-')
				{
					sig=-1;
					continue;
				}
				sum=sum*10+chr[i]-'0';
			}
			sum*=sig;a[tar]=sum;continue;//printf("%d\n",a['A']);
		}
		if(s[0]=='O'&&s[1]=='U')
		{
			printf("%d\n",a[chr[0]]);continue;
		}
		if(s[0]=='M'&&s[2]=='V')
		{
			a[chr[0]]=a[chr[3]];continue;
		}
		if(s[0]=='X'&&s[1]=='C')
		{
			int t=a[chr[0]];a[chr[0]]=a[chr[3]];a[chr[3]]=t;continue;
		}
		if(n>5)
		{
			tar=chr[0];sum1=a[chr[3]];sum2=a[chr[6]];
		}
		else 
		{
			tar=chr[0];sum1=a[chr[0]];sum2=a[chr[3]];
		}
		if(s[0]=='A')
		{
			if(s[1]=='D')a[tar]=sum1+sum2;
			else a[tar]=sum1&sum2;
		}
		else if(s[0]=='S')a[tar]=sum1-sum2;
		else if(s[0]=='M')
		{
			if(s[1]=='U')a[tar]=sum1*sum2;
			else a[tar]=sum1%sum2;
		}
		else if(s[0]=='D')a[tar]=sum1/sum2;
		else if(s[0]=='O')a[tar]=sum1|sum2;
		else a[tar]=sum1^sum2;
	}
	return 0;
}