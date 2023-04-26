#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
	char *a,*b;
	a=(char *)pa;
	b=(char *)pb;
	return strcmp(a,b);
}
int equal(char s1[],char s2[])
{
	if(strlen(s1)!=strlen(s2))
	{
		return -1;
	}
	else
	{
		int t=0;
		int l=strlen(s1);
		for(int i=0;i<l;i++)
		{
			if(s1[i]==s2[i])
			{
				t++;
			}
		}
		if(t==l)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
}
int main()
{
	int number;
	scanf("%d%c",&number);
	for(int i=0;i<number;i++)
	{
		char s[601];
		gets(s);
		int l=strlen(s);
		int t=0;
		for(int j=0;j<strlen(s);j++)
		{
			if(s[j]<'a'||s[j]>'z')
			{
				t++;
			}
		}
		char c[500][500];
		int count=0,j=0;
		while(1)
		{
			int k=0;
			while((s[j]>='a'&&s[j]<='z')&&s[j])
			{
				c[count][k++]=s[j++];
			}
			c[count][k]='\0';
			count++;
			if(!s[j])
			{
				break;
			}
			else
			{
				j++;
			}
		}
		qsort(c,count,sizeof(c[0]),cmp);
		printf("%s",c[0]);
		for(int j=1;j<count;j++)
		{
			if(equal(c[j-1],c[j])==1)
			{
				continue;
			}
			else
			{
				printf("%s ",c[j]);
			}
		}
		printf("\n");
	}
	return 0;
}