#include<stdio.h>
#include<string.h>
int main()
{
	char s[110];
	while(gets(s))
	{
		int i,j,k,flag=1;
		for(i=0;s[i];i++)
			if(s[i]=='/'&&s[i+1]=='/')break;
		for(j=0;j<i;j++)
			if(s[j]=='"')flag=0;
		if(flag)s[i]=0;
		if(strlen(s)==0)continue;
		int len=strlen(s);
		for(i=0;s[i];i++)
			if(s[i]=='/'&&s[i+1]=='*')break;
		for(j=0;s[j];j++)
			if(s[j]=='*'&&s[j+1]=='/')break;
		//printf("%d %d\n",i,j);
		if(i!=len&&j!=len)
		{
			char tmp[110];
			k=0;j+=2;
			for(j;s[j];j++)
				tmp[k++]=s[j];
			for(i,j=0;j<k;j++,i++)
				s[i]=tmp[j];
			s[i]=0;
		}
		else if(i==len&&j!=len)
		{
			k=j;
			for(j;j<len-1;j++)
				s[j]=s[j+1];
			for(j=k;j<len-2;j++)
				s[j]=s[j+1];
			s[len-2]=0;
		}
		else if(j==len&&i!=len)
		{
		    s[j]=0;
		    continue;
		}
		printf("%s\n",s);
	}
	return 0;
}