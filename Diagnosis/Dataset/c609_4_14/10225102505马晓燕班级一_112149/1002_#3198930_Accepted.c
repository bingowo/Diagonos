#include <stdio.h>
int count(long long n){
	int fir=n%2,sec=1;
	int temp=1,ret=1;
	n/=2;
	while(n){
		sec=n%2;
		if(fir != sec)
			temp++;
		else{
			if(temp>ret)
				ret = temp;
			temp=1;
		}
		fir=sec,n/=2;
	}
	if(temp>ret)
		ret=temp;
	return ret;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		long long n;
		scanf("%lld",&n);
		int len = count(n);
		printf("case #%d:\n",i);
		printf("%d\n",len);
		
	}
	return 0;
}