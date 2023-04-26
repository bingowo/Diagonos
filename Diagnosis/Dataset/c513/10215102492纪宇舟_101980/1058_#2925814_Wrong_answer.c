#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char s[1005];
int main()
{   /*/*/ 
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);
	int block=0,chr,nonzero,sig,sigpos,xing;
	while(gets(s)!=NULL)
	{
		chr=nonzero=sig=sigpos=xing=0;
		int n=strlen(s);
		if(s[0]==0){printf("\n");continue;}
		for(int i=0;i<n;i++)
		{
			if(i!=0)
			if(s[i]=='/'&&s[i-1]=='*'&&chr==0&&i-1!=xing)
			{
				block=0;i++;nonzero=1;if(i==n)break; 
			} 
			if(s[i]=='/'&&s[i+1]=='*'&&chr==0)
			{
				block=1;xing=i+1;
			}
			if(block){nonzero=0;continue;}
			if(s[i]=='/'&&s[i+1]=='/'&&chr==0){nonzero=1;break;}
			if(s[i]=='\\'&&sig==0){sig=1;sigpos=i;}
			if(s[i]=='\"'&&sig==0){chr=1-chr;}
			if(i!=sigpos)sig=0;
			printf("%c",s[i]);nonzero=1;
		}
		if(nonzero)printf("\n");
	}
	//fclose(stdin);fclose(stdout);
	return 0;
}