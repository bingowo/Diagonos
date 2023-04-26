#include<stdio.h>
#include<string.h>

int gcd(int a, int b)
{
	if (a < b)   
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if (a % b)
	{
		return gcd(b, a % b);  
	}
	return b; 
}

int main()
{
	int n;
	scanf_s("%d", &n);
	getchar();  
	for (int i = 0;i < n;i++)
	{
		char s[121];       
		int count1 = 0;       
		int count2 = 0;      
		gets_s(s);
		count2 = 8 * strlen(s);   
		for (int k = 0;k < strlen(s);k++)
		{
			for (int j = 0;j < 8;j++)
			{
				if ((s[k]) & (1 << j))
				{
					count1++;
				}
			}
		}
		printf("%d/%d", count1 / gcd(count1, count2), count2 / gcd(count1, count2));
		printf("\n");
	}
	return 0;
}
