#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
long long int f(int x)
{
	
	if(x==3) return 7;
	if(x==4) return 12;
	if(x==5) return 21;
	else return f(x-1)+f(x-1)-f(x-2)+f(x-3);
	
}
int main()
{
	int x;
	while(scanf("%d",&x)&&x!=-1)
	{
		printf("%lld",f(x));
	}
	return 0;
}