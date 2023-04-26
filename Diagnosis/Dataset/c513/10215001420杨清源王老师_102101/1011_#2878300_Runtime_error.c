#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char s[100];
	scanf("%s", s);
	
	long long ans = 0;
	int len = strlen(s) , i = 2;
	for(; i < len ; i++)
	{
		ans = ans * 16;
		if(s[i] >= '0' && s[i] <= '9')
			ans += s[i] - '0';
		if(s[i] >= 'A' && s[i] <= 'F')
			ans += s[i] - 'A' + 10;
	}
	
	if(ans == 0)
		printf("0");
	
	int a[64] , j = 0;
	while( ans != 0 )
	{
		a[j++] = ans % 2;
		ans /= 2;
	} 
	
	int real[64] , imag[64];
	real[0] = 1 , real[1] = -1;
	imag[0] = 0 , imag[1] = 1;
	for( i = 2 ; i < 64 ; i++)
	{
		real[i] = -1 * real[i - 1] - imag[i - 1];
		imag[i] = real[i - 1] - imag[i - 1];
	}
	
	long long int ans_real = 0 , ans_imag = 0;
	for( i = 0 ; i < j ; i++)
	{
		if(a[i])
		{
			ans_real += real[i];
			ans_imag += imag[i];
		}
	}
	
	if(ans_real != 0)
		printf("%lld",ans_real);
	if(ans_imag > 0)
	{
		if(ans_imag == 1 && ans_real != 0)
			printf("+i");
		if(ans_imag == 1 && ans_real == 0)
			printf("i");
		if(ans_imag != 1)
			printf("+%lldi",ans_imag);
	}	
	if(ans_imag < 0)
	{
		if(ans_imag == -1)
			printf("-i");
		else
			printf("%lldi",ans_imag);
	}
		
	return 0;
}

