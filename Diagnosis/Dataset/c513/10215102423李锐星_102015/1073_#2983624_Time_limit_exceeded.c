#include <stdio.h>

int check(unsigned long long a)
{
	if(a%9==0){
		return 0;
	}
	else{
		while(a>0){
			if(a%10==9){
				return 0;
			}
			else{
				a/=10;
			}
		}
	}
	return 1;
}

int main()
{
	unsigned long long a,b;
	scanf("%llu%llu",&a,&b);
	unsigned long long cnt=0;
	unsigned long long i;
	for (i=a;i<=b;i++){
		if(check(i)==1){
			cnt++;
		}
	}
	printf("%llu\n",cnt);
	return 0;
}