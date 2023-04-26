#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[17]={'\0'};
int cmp(const void *a,const void *b)
{
	char *a1=(char *)a;
	char *b1=(char *)b;
	return strcmp(a1,b1);
}
void copy(char *a,char *b)//将a不重复的字符复制进b 
{
	qsort(a,strlen(a),sizeof(a[0]),cmp);
	int i,j;
	int sign=0;
	b[0]=a[0];
	char mid[17]={'\0'};
	for(i=0;i<strlen(a);i++)
	{
		for(j=0;j<strlen(b);j++)
		{
			if(b[j]==a[i])sign=1;
		}
		if(sign=0)sprintf(mid,"%s%c",b,a[i]);
		strcpy(b,mid);
		sign=0;
	}
	return 0;
}
void comb(char *s,char *mid)
{
	if(*s)
	{
		char left[17];
		sprintf(left,"%s%c",mid,s[0]);
		printf("%s\n",left);
		comb(s+1,left);
		comb(s+1,mid);
	}
}

int main ()
{
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		char t[17],s[17];
		scanf("%s",t);
		copy(t,s);
		printf("case #%d:\n",i);
		comb(s,a);
	}
}