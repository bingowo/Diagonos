#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	long long int B,C;
	scanf("%lld%lld",&B,&C);
	char A[200];
	long long int a=B/C;
	if(a>0)	B=(C*a-B)>0?C*a-B:-1*(C*a-B);
	long long c=C;
	int i=0;
	int e=a;
	while(e>0)
	{
		A[i++]=e%3+'0';
		e/=3;
	}
	for(int e=0;e<i-1-e;e++)
	{
		char t;
		t=A[e];A[e]=A[i-1-e];A[i-1-e]=t;
	}
	if(a==0) A[i++]='0';
	if(C!=1)
	{
		A[i++]='.';
		while(c>1)
		{
			c/=3;
			A[i++]=B/c+'0';
			B-=(B/c)*c;
		}
	}
	A[i]='\0';
	int j=i-1;
	int x,ca=0;
	while(j>=0)
	{
		if(A[j]=='.') j--;
		x=A[j]-'0';
		if(x+ca+1==1) {ca=0;A[j]='0';}
		else if(x+ca+1==2) {ca=0;A[j]='1';}
		else if(x+ca+1==3) {ca=1;A[j]='2';}
		else if(x+ca+1==4) {ca=1;A[j]='0';}
		j--;
	}
	int o,q,f;
	for(q=0;q<i;q++)
	{
		if(A[q]=='.') 
		{
			f=i-1;
			while(A[f]=='0') f--;
			if(A[f]=='.') o=0;
			else o=1;
		
			}
	}
	if(o==0) i=f;
	else if(o==1) i=f+1;
	if(ca!=0)
	{
		printf("%d",ca);
		for(int g=0;g<i;g++) printf("%c",A[g]);
	}
	else for(int g=0;g<i;g++) printf("%c",A[g]);
	return 0;
	
}