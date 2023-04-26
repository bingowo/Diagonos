#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int toint(char* p,int ch)
{
	int result=0,i=0;
	while(i<ch)
	{
		result*=10;
		result+=(*(p+i)-'0');
		i++; 
	}
	return result;
}

void pr(int n,int ch)
{
	int i;
	for(i=ch-1;i>=0;i--)printf("%d",((n>>i)&1));
}

int main()
{
	int result,len;
	int i,j;
	char n[510],temp[4];
	scanf("%s",&n);
	len=strlen(n);
	printf("0001");
	pr(len,10);
	for(i=0;i<len;i=i+3)
	{
		if(len-i>=3)pr(toint(n+i,3),10);
		else if(len-i==2)pr(toint(n+i,2),7);
		else if(len-i==1)pr(toint(n+i,1),4);
	}
	return 0;
}