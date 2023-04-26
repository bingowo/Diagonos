#include <stdio.h>
long long int min(long long int x,long long int y)
{
	if(x==y) return 4*x;
	else{
		if(x>y) return 4*y+min(x-1,y);
		else return 4*x+min(x,y-x);
	}
}

int main()
{
	long long int x,y,v;
	scanf("%lld %lld",&x,&y);
	if(x>y&&x%y==0) v=(x/y)*(4*y);
	else if(y>x&&y%x==0) v=(y/x)*(4*x);
	else v=min(x,y);
	printf("%lld\n",v);
	return 0;
		
}