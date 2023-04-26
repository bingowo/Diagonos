#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long long int rtoi(char s)
{
	long long int ans;
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
			ans = 10000 ; break;
		case ')':
			ans = 0 ; break;
	}
	
	return ans;
} 

int main()
{
	char s[50];
	scanf("%s",s);
	
	int len = strlen(s) , i = 0 , flag = 0;
	long long sum = 0;
	
	for(; i < len ; i++)
	{
		while(rtoi(s[i]) == 10000)
		{
			i++;
			flag++;
		}
		
		
		
		while(rtoi(s[i]) != 0)
		{
			if(rtoi(s[i]) >= rtoi(s[i + 1]))
				sum += rtoi(s[i]);
			else 
				sum -= rtoi(s[i]);
			i++;
		}	
		
		sum *= pow(1000 , flag);
		flag = 0;
		
	}
	
	
	
	printf("%lld",sum);
	
	
	return 0;
}