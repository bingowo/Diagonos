#include <stdio.h>
int main()
{
	long long int num=0,i=0;
	scanf("%llx",&num);
	int L[10000]={0};
	while(num>0)
	{
		L[i]=num%2;
		num=num/2;
		i++;
	}
	long long int a=-1,b=1,A=0,B=0;
	long long int m=0,n=0;
	for(long long int k=1;k<i;k++)
	{
		m+=a*L[k];
		n+=b*L[k];
		A=a;
		B=b;
		a=-A-B;
		b=A-B;
	}
	m+=L[0];
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
	return 0;
}