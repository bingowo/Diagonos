#include <stdio.h>
int min(int x,int y)
{
	if(x==y) return 4*x;
	else{
		if(x>y) return 4*y+min(x-y,y);
		else return 4*x+min(x,y-x);
	}
}

int main()
{
	long long int x,y,v;
	scanf("%lld %lld",&x,&y);
	//if(x==y) v=4*x;
	v=min(x,y);
	printf("%lld\n",v);
	return 0;
		
}