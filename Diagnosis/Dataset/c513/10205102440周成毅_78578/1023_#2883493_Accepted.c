#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int cmp(const void *a, const void *b);
double extract(char *s);
 
int main()
{
	int i=0;
	char number[101][30];
	while(scanf("%s",number[i])!=EOF)
	{
		i++;
	}
	qsort(number,i,sizeof(number[0]),cmp);
	for(int j=0;j<i;j++)
	{
		printf("%s ",number[j]);
	}
	return 0;
}

int cmp(const void *a, const void *b)
{
	char * A;char * B;
	int m=0,n=0;
	int a_value,b_value;
	A=(char*)a; B=(char*)b;
	a_value=extract(A);
	b_value=extract(B);
	for(int i=0;i<strlen((char*)a);i++)
	{
		if (isdigit(((char *)a)[i]))
		{
			m=1;
			break;
		}
	}
	for(int i=0;i<strlen((char*)b);i++)
	{
		if (isdigit(((char *)b)[i]))
		{
			n=1;
			break;
		}
	}
	if(m==1 && n==1)
	{
		if(a_value!=0 && b_value==0)
	{
		return 1;
	}
	else if(a_value==0 && b_value!=0)
	{
		return -1;
	}
	else if(a_value==0 && b_value==0)
	{
		return strcmp(A,B);
	}
	else if(a_value!=0 && b_value!=0)
	{
		if(a_value!=b_value) return a_value-b_value;
		else return strcmp(A,B);
	}
	}
	else if(m==0 && n==1) return -1;
	else if(m==1 && n==0) return 1;
	else if(m==0 && n==0) return strcmp(A,B);
}


double extract(char *s)
{
	int i=0,temp;
	double count=0;
	while(s[i] && (s[i]<'0' || s[i]>'9'))
	{
		i++;
	}
	if(s[i])
	{
		temp=i+1;
		count=s[i]-'0';
		while(s[temp]>='0' && s[temp]<='9')
		{
			count=10*count+(s[temp]-'0');
			temp++;
		}
	}
	return count;
}