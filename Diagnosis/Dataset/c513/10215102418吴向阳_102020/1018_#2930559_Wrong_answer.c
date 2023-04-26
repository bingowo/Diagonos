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
	for (int i=m+1,j=25;i<j;i++,j--)
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
	int x[25]={96,88,82,78,72,70,66,60,58,52,46,42,40,36,30,28,22,18,16,12,10,6,4,2,1};
	for(int i=24;i>-1;i--)
	{
		product*=x[i];
		weigh[i]=product;
	}
	unsigned long long num=0;
	for(int i=0;i<25;i++)
	{
		num+=weigh[i]*t[i];
	}
	printf("%lld",num);
	return 0;
}