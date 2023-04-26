#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long long real(int n);
long long imag(int n);

int main()
{
	char s[10000];
	scanf("%s", s);
	
	long long ans = 0;
	int len = strlen(s) , i = 2;
	for(; i < len ; i++)
	{
		ans = ans * 16;
		if(s[i] >= '0' && s[i] <= '9')
			ans += s[i] - '0';
		if(s[i] >= 'A' && s[i] <= 'F')
			ans += s[i] - 'A';
	}
	
	if(ans == 0)
		printf("0");
	
	int a[10000] , j = 0;
	while( ans > 0 )
	{
		a[j++] = ans % 2;
		ans /= 2;
	} 
	
	long long int ans_real = 0 , ans_imag = 0;
	for( i = 0 ; i < j ; i++)
	{
		if(a[i])
			ans_real += real(i);
			ans_imag += imag(i);
	}
	
	if(ans_real != 0)
		printf("%lld",ans_real);
	if(ans_imag > 0)
	{
		if(ans_imag == 1)
			printf("+i");
		else
			printf("+%lldi",ans_imag);
	}	
	if(ans_imag < 0)
	{
		if(ans_imag == -1)
			printf("-i");
		else
			printf("-%lldi",ans_imag);
	}
		
	return 0;
}


long long real(int n)//n代表（i-1）的幂次 
{
	if(n == 0)
		return 1;
	if(n == 1)
		return -1;
	else
		return -1 * real(n - 1) - imag(n - 1);
}

long long imag(int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	else 
		return real(n - 1) - imag(n - 1);
}