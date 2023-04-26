#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
int hex2dec(const char* str)
{
	int ans=0,i,tmp;
	for(i=0;str[i];i++)
	{
		if(isdigit(str[i]))tmp=str[i]-48;
		else tmp=str[i]-55;
		ans=ans*16+tmp;
	}
	return ans;
}
int legal(const char* s)
{
	int i,q,end,ans1=s[1],ans2;char tmp[100];
	if(!(s[0]=='$'&&s[1]=='G'&&s[2]=='P'&&s[3]=='R'&&s[4]=='M'&&s[5]=='C'))return 0;
	for(i=0;s[i];++i)if(s[i]==',')break; for(++i;s[i];++i)if(s[i]==',')break;
	if(s[++i]=='V')return 0;
	for(i=0;s[i];++i)if(s[i]=='*')break; end=i;
	for(++i,q=0;s[i];++i,q++)tmp[q]=s[i]; tmp[q]=0; ans2=hex2dec(tmp);
	for(i=2;i<end;++i)ans1^=s[i]; ans1%=65536;
	if(ans1!=ans2)return 0;
	return 1;
}
void print(int h,int m,int s)
{
	if(h<10)printf("0%d:",h);
	else printf("%d:",h);
	if(m<10)printf("0%d:",m);
	else printf("%d:",m);
	if(s<10)printf("0%d\n",s);
	else printf("%d\n",s);
}
int main()
{
	char s[1001];int i,h,m,se;char tmp[10];
	while(gets(s))
	{
		if(!(strcmp(s,"END")))
		{
			print(h,m,se);
			return 0;
		}
		else if(legal(s))
		{
			for(i=0;s[i];++i)if(s[i]==',')break;
			i++,tmp[0]=s[i++],tmp[1]=s[i++],tmp[2]=0,h=atoi(tmp)+8;
			tmp[0]=s[i++],tmp[1]=s[i++],tmp[2]=0,m=atoi(tmp);
			tmp[0]=s[i++],tmp[1]=s[i++],tmp[2]=0,se=atoi(tmp);
		}
	}
}