#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//int primes[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113};

int repr(char c)
{
	switch(c)
	{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		case '(':
			return 10000;
		default:
			return -1;
	}
}

int main()
{
	char input[55];
	int i,j,len;
	long long multiplier=1,result=0;
	scanf("%s",&input);
	len=strlen(input);
	for(i=0;i<len;i++)
	{
		if(input[i]=='(')multiplier*=1000;
		else if(input[i]==')')multiplier/=1000;
		else result=result+repr(input[i])*(repr(input[i])>=repr(input[i+1])?1:-1)*multiplier;
	}
	printf("%lld",result);
	return 0;
}