#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	char s[100],a[160][80];
	while(scanf("%s",s)!=EOF)
	{
		int i=80,m=80,n=80;
		int d=strlen(s);
		for(int j=0;j<160;j++)
		{
			for(int k=0;k<80;k++)
			{
				a[j][k]=' ';
			}
		}
		a[80][0]=s[0];
		for(int j=1;j<d;j++)
		{
			if(s[j]>s[j-1])	
			{
				i--;a[i][j]=s[j];
				if(i<m) m=i;
			}
			else if(s[j]<s[j-1]) 
			{
				i++;a[i][j]=s[j];
				if(i>n) n=i;
			}
			else {a[i][j]=s[j];}
		}
		for(int i=m;i<=n;i++)
		{
			for(int j=0;j<80;j++)
			{
				printf("%c",a[i][j]);
			}
			printf("\n");
		}
		
		
	}
}