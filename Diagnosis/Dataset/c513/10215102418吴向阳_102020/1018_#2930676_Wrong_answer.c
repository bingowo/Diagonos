#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readnumber(char s[],int t[])
{
	const char* delim=",";
	char *p=strtok(s,delim);
	int m=24;
	while(p!=NULL)
	{
		t[m]=atoi(p);
		m--;
		p=strtok(NULL,delim);
	}
	for (int i=m+1,j=24;i<j;i++,j--)
	{
		int temp=t[i];
		t[i]=t[j];
		t[j]=temp;
	}
}


int main()
{
	char s[100];
	int t[25]={0};
	scanf("%s",s);
	readnumber(s,t);
	unsigned long long weigh[25],product=1;
	int x[25]={91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
	for(int i=24;i>-1;i--)
	{
		weigh[i]=product;
		product*=x[i];
	}
	unsigned long long num=0;
	for(int i=0;i<25;i++)
	{
		num+=weigh[i]*t[i];
	}
	printf("%lld",num);
	return 0;
}