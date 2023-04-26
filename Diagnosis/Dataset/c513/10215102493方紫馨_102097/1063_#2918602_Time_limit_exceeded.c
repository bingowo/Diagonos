#include<stdio.h>
long long int field(long long int x,long long int y){
	long long int ret,t;
	while(x!=y){
		if(x<y){
			t=x;x=y;y=t;
		}
		ret+=y*4;
		x-=y;
	}
	ret+=x*4;
	return ret;
}

int main()
{
	long long int x,y;
	scanf("%lld%lld",&x,&y);	
	printf("%lld",field(x,y));
	return 0;
}