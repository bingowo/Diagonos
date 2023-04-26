#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int n,cnt=0;
	char s[200]={0}; 
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++)
	{
		cnt=0;
		gets(s);
		s[strlen(s)]=' ';
		s[strlen(s)]=' ';
		s[strlen(s)]=' ';
		for(int j=0;j<strlen(s)-2;j++)
		{
			tolower(s[j]);
			if(s[j]==' '||j==strlen(s))
				cnt++;
			if(s[j]=='a'&&(s[j-1]==' '||j==0)&&s[j+1]==' ')
				cnt--;
			if(s[j]=='t'&&s[j+1]=='h'&&s[j+2]=='e'&&(s[j-1]==' '||j==0)&&s[j+3]==' ')
				cnt--;
			if(s[j]=='a'&&s[j+1]=='n'&&s[j+2]=='d'&&(s[j-1]==' '||j==0)&&s[j+3]==' ')
				cnt--;
			if(s[j]=='f'&&s[j+1]=='o'&&s[j+2]=='r'&&(s[j-1]==' '||j==0)&&s[j+3]==' ')
				cnt--;
			if(s[j]=='a'&&s[j+1]=='n'&&(s[j-1]==' '||j==0)&&s[j+2]==' ')
				cnt--;
			if(s[j]=='o'&&s[j+1]=='f'&&(s[j-1]==' '||j==0)&&s[j+2]==' ')
				cnt--;
		}
		printf("case# %d:\n%d%\n",i,cnt);
	}
}