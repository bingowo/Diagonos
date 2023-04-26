#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int n,cnt,i,j;
	char s1[200]={0},s[200]={0}; 
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		cnt=-2;
		gets(s1);
		s1[strlen(s1)]=' ';
		s1[strlen(s1)]=' ';
		s1[strlen(s1)]=' ';
		for(j=0;j<strlen(s1);j++)
		{
			s[j]=tolower(s1[j]);
		}
		for(j=0;j<strlen(s);j++)
		{
			if(s[j]==' ')
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
		printf("case# %d:\n%d\n",i,cnt);
	}
}