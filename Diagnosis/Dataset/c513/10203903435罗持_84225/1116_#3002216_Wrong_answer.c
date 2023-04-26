#include <stdio.h>
#define ll long long
ll x,y;
ll llabs(ll x){
	if(x>=0) return x;
	else return -1*x;
}
int main(void)
{
	scanf("%lld %lld",&x,&y);
	if(x==0 && y==0){
		printf("0");
		return 0;
	}
	if((llabs(x)+llabs(y))%2==0){
		printf("-1");
		return 0;
	}
	int ret = -1;
	for(int i=0;i<=41;i++){
		if((1<<i) < llabs(x)+llabs(y)+1 && llabs(x)+llabs(y)+1 <= (1<<(i+1))){
			ret = i;
			break;
		}
	} 
	printf("%d",ret+1);
	return 0;
}