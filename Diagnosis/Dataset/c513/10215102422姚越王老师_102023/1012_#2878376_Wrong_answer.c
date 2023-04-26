#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long myatol(const void* a)
{
	char* str=(char*)a;int sign=1,i=0;
	if(str[0]=='-'){
		sign=-1;
		i++;
	}
	long long ans=0;
	for(i;i<strlen(str);i++)ans=ans*10+str[i]-48;
	return ans*sign;
}
int main()
{

	char s[1005];scanf("%s",s);
	long long a,b;
	if(strchr(s,'+')!=0)
	{
		int i;
		for(i=0;i<strlen(s);i++)if(s[i]=='+')break;
		char sa[1005];
		strncpy(sa,s,i);
		a=myatol(sa);
		char sb[1005];i++;int j;
		for(i,j=0;i<strlen(s)-1;i++,j++)sb[j]=s[i];
		sb[j]=0;
		b=myatol(sb);
	}
	else if(strchr(s,'-')!=0&&s[0]!='-')
	{
		int i;
		for(i=0;i<strlen(s);i++)if(s[i]=='-')break;
		char sa[1005];
		strncpy(sa,s,i);
		a=myatol(sa);
		char sb[1005];int j;
		for(i,j=0;i<strlen(s)-1;i++,j++)sb[j]=s[i];
		sb[j]=0;
		b=myatol(sb);
	}
	else if(strchr(s,'i')!=0)
	{
		char sb[1005];
		strncpy(sb,s,strlen(s)-1);
		b=myatol(sb);a=0;
	}
	else {a=myatol(s);b=0;}
	int bina[300];
	for(int i=0;i<300;i++)bina[i]=0;
	int i;
	for(i=0;i<300;i++)
	{
		long long t=a+b;
		long long qr=a,qi=b;
		if(t%2==0)
		{
			bina[i]=0;
			qr=(a-b)/(-2);
			qi=(a+b)/(-2);
		}
		else
		{
			bina[i]=1;
			qr=(a-b-1)/(-2);
			qi=(a+b-1)/(-2);
		}
		a=qr;b=qi;
		if(a==0&&b==0)break;
	}
    for(i;i>=0;i--)printf("%d",bina[i]);
	return 0;
}