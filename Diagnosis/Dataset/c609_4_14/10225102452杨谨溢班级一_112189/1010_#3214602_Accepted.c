# include <stdio.h>
# include <math.h>
char C[] = "0123456789ABCDEFGHIJ";
void printd(int n,int BASE)
{
	if (n != 0)
	{
		int a = n % BASE;
		if (a >= 0)  printd(n / BASE , BASE);
		else {
			printd( n / BASE + 1, BASE);
			a = a - BASE;
		}
		printf("%c", C[a]);
	}
	return;
}
int main()
{
	int n, BASE;
	scanf("%d %d", &n, &BASE);
	if (n == 0)   printf("0");
	printd(n, BASE);
	return 0;
}