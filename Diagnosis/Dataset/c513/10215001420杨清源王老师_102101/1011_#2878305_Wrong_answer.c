#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char s[100];
	scanf("%s", s);
	int len = strlen(s) - 2;
	
	int a[4 * len] , i = 0;
	
	for(; i < len ; i++)
	{
		if(s[i + 2] == '0')
		{
			a[4 * i] = 0;
			a[4 * i + 1] = 0;
			a[4 * i + 2] = 0;
			a[4 * i + 3] = 0;
		}
		if(s[i + 2] == '1')
		{
			a[4 * i] = 0;
			a[4 * i + 1] = 0;
			a[4 * i + 2] = 0;
			a[4 * i + 3] = 1;
		}
		if(s[i + 2] == '2')
		{
			a[4 * i] = 0;
			a[4 * i + 1] = 0;
			a[4 * i + 2] = 1;
			a[4 * i + 3] = 0;
		}
		if(s[i + 2] == '3')
		{
			a[4 * i] = 0;
			a[4 * i + 1] = 0;
			a[4 * i + 2] = 1;
			a[4 * i + 3] = 1;
		}
		if(s[i + 2] == '4')
		{
			a[4 * i] = 0;
			a[4 * i + 1] = 1;
			a[4 * i + 2] = 0;
			a[4 * i + 3] = 0;
		}
		if(s[i + 2] == '5')
		{
			a[4 * i] = 0;
			a[4 * i + 1] = 1;
			a[4 * i + 2] = 0;
			a[4 * i + 3] = 1;
		}
		if(s[i + 2] == '6')
		{
			a[4 * i] = 0;
			a[4 * i + 1] = 1;
			a[4 * i + 2] = 1;
			a[4 * i + 3] = 0;
		}
		if(s[i + 2] == '7')
		{
			a[4 * i] = 0;
			a[4 * i + 1] = 1;
			a[4 * i + 2] = 1;
			a[4 * i + 3] = 1;
		}
		if(s[i + 2] == '8')
		{
			a[4 * i] = 1;
			a[4 * i + 1] = 0;
			a[4 * i + 2] = 0;
			a[4 * i + 3] = 0;
		}
		if(s[i + 2] == '9')
		{
			a[4 * i] = 1;
			a[4 * i + 1] = 0;
			a[4 * i + 2] = 0;
			a[4 * i + 3] = 1;
		}
		if(s[i + 2] == 'A')
		{
			a[4 * i] = 1;
			a[4 * i + 1] = 0;
			a[4 * i + 2] = 1;
			a[4 * i + 3] = 0;
		}
		if(s[i + 2] == 'B')
		{
			a[4 * i] = 1;
			a[4 * i + 1] = 0;
			a[4 * i + 2] = 1;
			a[4 * i + 3] = 1;
		}
		if(s[i + 2] == 'C')
		{
			a[4 * i] = 1;
			a[4 * i + 1] = 1;
			a[4 * i + 2] = 0;
			a[4 * i + 3] = 0;
		}
		if(s[i + 2] == 'D')
		{
			a[4 * i] = 1;
			a[4 * i + 1] = 1;
			a[4 * i + 2] = 0;
			a[4 * i + 3] = 1;
		}
		if(s[i + 2] == 'E')
		{
			a[4 * i] = 1;
			a[4 * i + 1] = 1;
			a[4 * i + 2] = 1;
			a[4 * i + 3] = 0;
		}
		if(s[i + 2] == 'F')
		{
			a[4 * i] = 1;
			a[4 * i + 1] = 1;
			a[4 * i + 2] = 1;
			a[4 * i + 3] = 1;
		}
	}
	
	if(s[2] == '0')
		printf("0");
	
	long long int real[64] , imag[64];
	real[0] = 1 , real[1] = -1;
	imag[0] = 0 , imag[1] = 1;
	for( i = 2 ; i < 64 ; i++)
	{
		real[i] = -1 * real[i - 1] - imag[i - 1];
		imag[i] = real[i - 1] - imag[i - 1];
	}
	
	long long int ans_real = 0 , ans_imag = 0;
	for( i = 0 ; i < 4 * len ; i++)
	{
		if(a[i])
		{
			ans_real += real[4 * len - 1 - i];
			ans_imag += imag[4 * len - 1 - i];
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

