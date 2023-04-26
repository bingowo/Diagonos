#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char s[50];
	int L[300]={0};
	int i=0;
	scanf("%s",s);
	for(int k=2;k<strlen(s);k++) 
	{
		int d=0;
		if(s[k]>='A') d=s[k]-'A'+10;
		else d=s[k]-'0';
		unsigned int flag=0x8;
		while(flag)
		{
			if(d&flag) L[i++]=1;
			else L[i++]=0;
			flag=flag>>1;
		}
	}
	long long int a=-1,b=1,A=0,B=0;
	long long int m=0,n=0;
	for(int k=i-2;k>0;k--)
	{
		m+=a*L[k];
		n+=b*L[k];
		A=a;
		B=b;
		a=-A-B;
		b=A-B;
	}
	m+=L[i-1];
	
	if(n!=1 && n!=-1)
	{
		if(m==0 && n!=0) printf("%lldi",n);
		else if(n==0) printf("%lld",m);
		else if(n<0) printf("%lld%lldi",m,n);
		else printf("%lld+%lldi",m,n);
		return 0;
	}
	else
	{
		if(n==1)
		{
			if(m==0)printf("i");
			else printf("%lld+i",m);
		}
		else
		{
			if(m==0)printf("-i");
			else printf("%lld-i",m);
		}
	}

}