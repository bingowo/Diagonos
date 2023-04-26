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
		int tmp1,tmp2;
		scanf("%s%s%s",s1,s2,s);
		int len1=strlen(s1),len2=strlen(s2),len=strlen(s);
		if(get_first(s1,s)==-1||get_first(s2,s)==-1)printf("case #%d:\n%d\n",i,0);
		else if(strcmp(s1,s2)!=0)
		{
			tmp1=get_last(s2,s)-get_first(s1,s)-len1;
			tmp2=get_last(s1,s)-get_first(s2,s)-len2;
			printf("case #%d:\n%d\n",i,tmp1>tmp2?tmp1:tmp2);
		}
		else if(get_first(s1,s)==get_last(s1,s))printf("case #%d:\n%d\n",i,0);
		else printf("case #%d:\n%d\n",i,get_last(s1,s)-get_first(s1,s)-len1);
	}
	return 0;
}