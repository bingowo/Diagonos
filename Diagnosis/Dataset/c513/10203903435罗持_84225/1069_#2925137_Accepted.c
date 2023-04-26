#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int n;
int cnt = 0;
int huiwen(int x)
{
	int res = 0;
	int n = x;
	while(n)
	{
		res = res*10 + n%10;
		n /= 10;
	}
	return res;
}
int main(void)
{
	scanf("%d",&n);
	while(1)
	{
		int hui = huiwen(n);
		cnt++;
		if(hui==n)
		{
		    printf("%d %d",cnt-1,n);
			break;
		}
		else n = n+hui;
	} 
	return 0;
}