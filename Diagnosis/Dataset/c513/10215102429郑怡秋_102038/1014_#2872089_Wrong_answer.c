#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
	long long int B,C;
	scanf("%lld%lld",&B,&C);
	char A[200];
	long long int a=B/C;
	B=C*a-B;
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
		x=A[j]-'0';
		if(A[j]='.') j--;
		if(x+ca+1==1) {ca=0;A[j]='0';}
		else if(x+ca+1==2) {ca=1;A[j]='1';}
		else if(x+ca+1==3) {ca=1;A[j]='2';}
		else if(x+ca+1==4) {ca=2;A[j]='0';}
		j--;
	}
	if(ca==1) 
	{
		int k1=0,k2=i-1;
		while(A[k1++]=='0');
		while(A[k2--]=='0');
		while(k1<k2) printf("%s",A[k1++]);
	}
	else
	{
		int k2=i-1;
		printf("%d",ca-1);
		while(A[k2--]=='0');
		for(int q=0;q<=k2;q++) printf("%s",A[q]);
	}
	return 0;
	
}