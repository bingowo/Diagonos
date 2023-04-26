#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char s[101],c;
int main()
{
	int len,ans;
	int ct=0,T;scanf("%d\n",&T);
	while(T--)
	{
		len=ans=0;
		while(1)
		{
			c=getchar();
			if(c==' '||c=='\n')
			{
				s[len]='\0';ans++;
				if(strlen(s)==1&&(s[0]=='a'||s[0]=='A'))ans--;
				if(strlen(s)==2&&(s[0]=='a'||s[0]=='A')&&(s[1]=='n'||s[1]=='N'))ans--;
				if(strlen(s)==2&&(s[0]=='o'||s[0]=='O')&&(s[1]=='f'||s[1]=='F'))ans--;
				if(strlen(s)==3&&(s[0]=='t'||s[0]=='T')&&(s[1]=='h'||s[1]=='H')&&(s[2]=='e'||s[2]=='E'))ans--;
				if(strlen(s)==3&&(s[0]=='f'||s[0]=='F')&&(s[1]=='o'||s[1]=='O')&&(s[2]=='r'||s[2]=='R'))ans--;
				if(strlen(s)==3&&(s[0]=='a'||s[0]=='A')&&(s[1]=='n'||s[1]=='N')&&(s[2]=='d'||s[2]=='D'))ans--;
				if(c=='\n')break;
				len=0;
			}
			else s[len++]=c;
		}
		printf("case #%d:\n",ct++);
		printf("%d\n",ans);
	}
	return 0;
}