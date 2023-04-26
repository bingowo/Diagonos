#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int rtoi(char s)
{
	int ans;
	switch(s)
	{
		case 'I':
			ans = 1 ; break;
		case 'V':
			ans = 5 ; break;
		case 'X':
			ans = 10 ; break;
		case 'L':
			ans = 50 ; break;
		case 'C':
			ans = 100 ; break;
		case 'D':
			ans = 500 ; break;
		case 'M':
			ans = 1000 ; break;
		case '(':
			return 1000 * rtoi(s++);
	}
	
	return ans;
} 

int main()
{
	char s[50];
	scanf("%s",s);
	int len = strlen(s) , i = 0;
	long long sum = 0;
	
	for(; i < len - 1 ; i++)
	{
		if(rtoi(s[i]) >= rtoi(s[i + 1]))
			sum += rtoi(s[i]);
		else 
			sum -= rtoi(s[i]);
	}
	
	sum += rtoi(s[len - 1]);
	
	
	printf("%lld",sum);
	
	
	return 0;
}