# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

char C[] = "0123456789ABCDEF";
void printd(long long int n, int r)
{
	if (n > 0)
	{
		printd(n / r, r);
		putchar(C[n % r]);
	}
}

int main()
{
	int a, b;
	char str[35];
	scanf("%d %s %d", &a, str, &b);
	long long num = 0;
	for (int e = 0;e<strlen(str);++e)
	{
		if (isdigit(str[e])) {
			num = num * a + str[e] - '0';
			//printf("MM%lld\n", num);
		}
		else num = num * a + 10 +(str[e] < 'a' ? str[e] - 'A' : str[e] - 'a');
	}
	//printf("MM%lld\n", num);
	if (num == 0)  putchar('0');
	printd(num, b);
	return 0;
}
