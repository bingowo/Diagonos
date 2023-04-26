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
				s[len]='\0';
				if(strcmp(s,"the")!=0&&strcmp(s,"a")!=0&&strcmp(s,"an")!=0&&strcmp(s,"of")!=0&&strcmp(s,"for")!=0&&strcmp(s,"ans")!=0)
				ans++;
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