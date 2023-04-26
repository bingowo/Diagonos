#include<stdio.h>
typedef unsigned long long llu;
llu solve(llu x,llu y)
{
	if(x==y)return 4*x;
	if(!(x%y))return x/y*4*y;
	return x>y?4*y+solve(x-y,y):4*x+solve(y-x,x);
}
int main()
{
	llu x,y;
	scanf("%llu %llu",&x,&y);
	printf("%llu",solve(x,y));
	return 0;
}