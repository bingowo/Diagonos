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
	long long int x,y,t,ret;
	scanf("%lld%lld",&x,&y);
	if(x<y){
			t=x;x=y;y=t;
		}
	if(x%y==0)
		ret=(x/y)*y*4;
	else	
		ret=field(x,y);
	printf("%lld",ret);
	return 0;
}