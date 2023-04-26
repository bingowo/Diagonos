#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b);

int main()
{
	int T;
	char **email;
	scanf("%d",&T);
	email=(char **)malloc(T*sizeof(char *));
	char s[1000001],*p;
	int i,len;
	for(i=0;i<T;i++)
	{
		scanf("%s",s);
		len=strlen(s);
		p=(char *)malloc(len+1);
		strcpy(p,s);
		*(email+i)=p;
	}
	qsort(email,T,sizeof(email[0]),cmp);
	for(int j=0;j<T;j++)
	{
		printf("%s\n",email[j]);
	}
	return 0;
 } 


int cmp(const void *a, const void *b)
{
	char* A;char* B;
	char c=64;
	int temp;
	A=strchr((*(char**)a),c);
	B=strchr((*(char**)b),c);
	temp=strcmp(A,B);
	if(temp!=0)
	{
		return temp;
		
	}
	else if(temp==0)
	{
		return -strcmp(*(char**)a, *(char**)b);
	}
}