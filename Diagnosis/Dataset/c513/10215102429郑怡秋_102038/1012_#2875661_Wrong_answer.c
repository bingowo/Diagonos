#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char A[10];
	scanf("%s",A);
	long long a=0,b=0;
	int l=strlen(A);
	int bi=0;
	for(int i=0;i<l;i++) {if(A[i]=='i') bi=1;}
	if(bi==0)//说明输入的不带i 
	{
		if(A[0]=='-')
		{
			int i=1;
			while(i<l) {a=a*10+A[i++]-'0';}
			a=-1*a;
		}
		else{
			int i=0;
			while(i<l) {a=a*10+A[i++]-'0';}
		}
	}
	else if(bi!=0)
	{
		int i=0,sign1=1,sign2=1;
		if(A[i]=='-') i++,sign1=-1;
		int j;
		for(j=i;j<l;j++)
		{
			if(A[j]=='-') {sign2=-1;break;}
			else if(A[j]=='+') {sign2=1;break;}
		}int i1;
		for(i1=i;i1<j;i1++) a=a*10+A[i1]-'0';
		
		for(int i2=j+1;i2<l-1;i2++) b=b*10+A[i2]-'0';
		a=sign1*a;
		if(b==0) b=1;
		b=sign2*b;
	}
	printf("%lld %lld",a,b);
	int B[100];int r=0;
	while(a==0&&b==0)
	{
		if((a%2==0&&b%2==0)||((a+1)%2==0&&(b+1)%2==0)) B[r++]=0;
		else B[r++]=1;
	}
	int kk=0;
	while(kk<r) printf("%d",B[kk++]);
	
	return 0;
}