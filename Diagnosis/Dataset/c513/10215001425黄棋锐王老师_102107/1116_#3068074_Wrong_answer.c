#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long ABS(long long x)
{
	if(x<0) return -x;
	else return x;
}

int main() 
{ long long x,y;
	scanf("%lld%lld",&x,&y);
	int i=1;
	if(x==0&&y==0) printf("0");
	else if(ABS(x)%2!=ABS(y)%2)//sigma(2^n-1)为奇数，奇数曼哈顿距离才有解 
	{
		while(1)
		{	
			if((1LL<<i)>=ABS(x)+ABS(y)+1&&ABS(x)+ABS(y)+1>(1LL<<i-1)) break;//即2^i-1>=|x|+|y|>2^(i-1)-1 
			i++;
		}
		printf("%d",i);
		 } 	

    return 0;
}