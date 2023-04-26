#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char s[1005];
int main()
{
	int block=0,chr,nonzero;
	while(gets(s)!=NULL)
	{
		chr=nonzero=0;
		int n=strlen(s);
		for(int i=0;i<n;i++)
		{
			if(i!=0)
			if(s[i]=='/'&&s[i-1]=='*'&&chr==0)block=0,i++;
			if(s[i]=='/'&&s[i+1]=='*'&&chr==0)block=1;
			if(block)continue;
			if(s[i]=='/'&&s[i+1]=='/'&&chr==0){nonzero=1;break;}
			if(s[i]=='\"'&&s[i-1]!='\\')chr=1-chr;
			printf("%c",s[i]);nonzero=1;
		}
		printf("\n");
	}
	return 0;
}