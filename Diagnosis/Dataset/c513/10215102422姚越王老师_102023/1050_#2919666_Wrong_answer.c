#include<stdio.h>
#include<string.h>
int get_first(const char* s1,const char* s)
{
	int i,j,k,flag,len1=strlen(s1),len=strlen(s);
	for(i=0;i<len-len1+1;i++)
	{
		if(s[i]==s1[0])
		{
			flag=1;
			for(j=i,k=0;k<len1;j++,k++)
			{
				if(s[j]!=s1[k]){flag=0;break;}
			}
			if(flag)return i;
		}
	}
	return -1;
}
int get_last(const char* s2,const char* s)
{
	int i,j,flag,k,len2=strlen(s2),len=strlen(s);
	for(i=len-len2;i>=0;i--)
	{
		if(s[i]==s2[0])
		{
			flag=1;
			for(j=i,k=0;k<len2;j++,k++)
			{
				if(s[j]!=s2[k]){flag=0;break;}
			}
			if(flag)return i;
		}
	}
	return -1;
}
int main()
{
	int T;scanf("%d",&T);
	int i,j,k;
	for(i=0;i<T;i++)
	{
		char s1[81],s2[81],s[81];
		scanf("%s%s%s",s1,s2,s);
		int len1=strlen(s1),len2=strlen(s2),len=strlen(s);
		int start1,start2;
		start1=get_first(s1,s);
		start2=get_last(s2,s);
		if(start1==-1||start2==-1)printf("case #%d:\n%d\n",i,0);
		else printf("case #%d:\n%d\n",i,start2-start1-len1);
	}
	return 0;
}