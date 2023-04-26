#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int rtoi(char s[] , int i)
{
	int ans;
	switch(s[i])
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
			return 1000 * rtoi(s,i+1);
		case ')':
			return rtoi(s,i+1);
	}
	
	return ans;
}


int main()
{
	char s[50];
	scanf("%s",s);
	char *p = s;
	int len = strlen(s) , i = 0;
	long long sum = 0 , tmp = 0;
	
	for(; i < len - 1 ; i++)
	{
		if(rtoi(s,i) >= rtoi(s,i + 1))
			sum += rtoi(s,i);
		else 
			sum -= rtoi(s,i);
	}
	
	printf("%lld",sum);
}