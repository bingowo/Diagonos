#include<stdio.h>
#include<math.h>

int main()
{
	int a[100]={0};
	long long num = 0;
	char c;
	int i=0;
	while((c=getchar())!='\n')
    {
		if(c >= 'A' && c <= 'F')
		{
			a[i] = (int)c - 55;
		}
		else if(c >= 'a' && c <= 'f')
		{
			a[i] = (int)c - 87;
		}
		else if(c >= '0' && c <= '9')
		{
			a[i] = (int)c - 48;
		}
		else
		{
			i--;
		}
		i++;
	}
	for(int j = 0; j < i; j++)
	{
		int k = i - j - 1;
		num = num + a[j] * pow(16,k);
	}
	printf("%lld",num);
	return 0;
}
