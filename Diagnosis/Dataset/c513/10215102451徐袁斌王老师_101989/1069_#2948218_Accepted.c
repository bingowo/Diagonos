#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int f(int x)
{
	int a=0;
	while(x)
	{
		a=a*10+x%10;
		x=x/10;
	}
	return a;
}
int main()
{
	int x,y=0;
	scanf("%d",&x);
	while(x!=f(x))
	{
		x=x+f(x);y++;
	}
	printf("%d %d",y,x);
	
	
	return 0;
	
 } 