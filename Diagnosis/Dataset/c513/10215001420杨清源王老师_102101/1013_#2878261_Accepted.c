#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a , int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b , a%b);
} 


int main()
{
	//对整数部分和小数部分分别求解
	char s[30];
	scanf("%s",s);
	int len = strlen(s) , flag = 0;
	
	long long int ansA = 0;
	for(; flag < len ; flag++)
	{
		if(s[flag] == '.')
			break;
		ansA = ansA * 3;
		if( s[flag] == '1')
			ansA += 1;
		if( s[flag] == '2')
			ansA -= 1;
	}
	
	long long int ansB = 0 , ansC = 1;
	flag = flag + 1;
	
	for(; flag < len ; flag++)
	{
		ansB = ansB * 3;
		ansC = ansC * 3;
		if( s[flag] == '1')
			ansB += 1;
		if( s[flag] == '2')
			ansB -= 1;
	}

	if(ansA > 0 && ansB < 0)
	{
		ansA--;
		ansB = ansC + ansB;
	}
	
	if(ansA < 0 && ansB > 0)
	{
		ansA++;
		ansB = ansC - ansB;
		if(ansA == 0)
			ansB = -ansB;
	}
	
	long long t = gcd(abs(ansB) , abs(ansC));
	
	if(ansB == 0)
		printf("%lld\n",ansA);
	else
	{
		if(ansA != 0)
			printf("%lld ",ansA);
		printf("%lld %lld\n",ansB/t,ansC/t);
	}
	
	
	return 0;
}