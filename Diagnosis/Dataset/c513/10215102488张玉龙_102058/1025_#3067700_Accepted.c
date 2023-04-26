#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char str[21];
	int a;
} S;

int cmp(const void*a, const void*b)
{
	const S*x=a,*y=b;
	if(x->a==y->a)
	{
		return(strcmp(x->str,y->str));
	}
	else
	{
		return(y->a-x->a);
	}
}


int count(char*s)
{
	int tab[256]={0},n=0;
	for(int i=0,l=strlen(s);i<l;i++)
	{
		if(tab[s[i]]==0)
		{
			tab[s[i]]++;
			n++;
		}
	}
	return n; 
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		S s[101];
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%s",s[j].str);
			s[j].a=count(s[j].str);
		}
		qsort(s,n,sizeof(s[0]),cmp);
		printf("case #%d:\n",i);
		for(int k=0;k<n;k++)
		{
			printf("%s\n",s[k].str);
		}
	}
	return 0;
}
