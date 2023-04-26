#include <stdio.h>
#define ll long long
ll x,y;
ll llabs(ll x)
{
	if(x>=0) return x;
	else return -1*x;
}
void helper(ll x,ll y,int k){
	if(k){
		ll dis = (1LL<<(k-1));
		if(llabs(x)>llabs(y)){
			if(x>0){
				helper(x-dis,y,k-1);
				printf("E");
			}
			else{
				helper(x+dis,y,k-1);
				printf("W");
			}
		}
		else{
			if(y>0){
				helper(x,y-dis,k-1);
				printf("N");
			}
			else{
				helper(x,y+dis,k-1);
				printf("S");
			}
		}
	}
	return;
}
int main(void)
{
	scanf("%lld %lld",&x,&y);
	if(x==0 && y==0){
		printf("0");
		return 0; 
	}
	if((llabs(x) + llabs(y))%2==0){
		printf("-1");
		return 0;
	}
	int i = 0;
	ll len = 1;
	for(i=0;i<=41;i++){
		if(len<llabs(x)+llabs(y)+1 && llabs(x)+llabs(y)+1<=len*2)
		{
			i++;
			break;
		}
		len *= 2;
	}
	printf("%d\n",i);
	helper(x,y,i);
	return 0;
} 