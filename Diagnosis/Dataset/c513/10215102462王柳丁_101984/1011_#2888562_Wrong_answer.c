#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char hex[10000];
	scanf("0x%s",hex);
	char bin[10000];
	int i,eve,j;
	for(i=0;i<strlen(hex);i++)
	{
		if(hex[i]>='A')eve=hex[i]-'A'+10;
		else eve=hex[i]-'0';
		for(j=0;j<4;j++)
		{
			bin[(i+1)*4-j-1]='0';
			if((eve&(1<<j))==(1<<j))bin[(i+1)*4-j-1]='1';
		}
		
	}
	long long int a=0,b=0,r=0;
	long long int q1=0,q2=0;
	for(i=0;i<strlen(bin);i++)
	{
		r=bin[i]-'0';
		a=q1,b=q2;
		q1=-a-b+r;
		q2=a-b;
	}
	if(q1==0&&q2!=0)printf("%lldi",q2);
	else if(q1!=0&&q2==0)printf("%lld",q1);
	else if(q1==0&&q2==0)printf("0");
	else if(q2<0)printf("%lld%lldi",q1,q2);
	else if(q2>0)printf("%lld+%lldi",q1,q2);
	return 0;
}