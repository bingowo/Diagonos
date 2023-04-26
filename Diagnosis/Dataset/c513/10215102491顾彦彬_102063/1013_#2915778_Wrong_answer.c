#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int table[3]={0,1,-1};
main()
{
	char input[31];
	long long int location_point=-1,A=0,B=0,C=1,weight=1,weight2=1,i=0;
	scanf("%s",input);
	for (i;input[i];i++)
	{
		if (input[i]=='.')
			location_point=i;
	}
	if (location_point==-1)
		location_point=strlen(input);
	for (int i=location_point-1;i>=0;i--)
	{
		A=A+weight*(table[input[i]-'0']);
		weight=weight*3;
	}
	if (location_point==strlen(input))
	{
		printf("%lld",A);
	}
	else
	{
	for (int j=strlen(input)-1;j>location_point;j--)
	{
		C=C*3;
		B=(table[input[j]-'0'])*weight2+B;
		weight2*=3;
	}
	if(B<0)
	{
		if(A>0)
		{
			A=A-1;
			B=C+B;
		}
		if (A==0)
			B=-B;
	} 
	while(B%3==0)
	{
		B/=3;
		C/=3;
	}
	if (A==0)
		printf("%lld %lld",B,C);
	if (A>0)
		printf("%lld %lld %lld",A,B,C);
	if (A<0)
		printf("%lld %lld %lld",A+1,C-B,C);
	}
}