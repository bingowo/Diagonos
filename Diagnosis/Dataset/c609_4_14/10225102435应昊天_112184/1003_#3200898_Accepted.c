#include<stdio.h>
#include<string.h> 
int main(){
	int T;
	scanf("%d",&T);
	long long n;
	int cnt;
	int a[100];
	int index = 0;
	for(int i = 0;i < T;i++){
		scanf("%lld",&n);
		if(n == 0)
			a[index++] = 0;
		while(n > 0){
			a[index++] = n % 2333;
			n /= 2333;
		}
		for(int j = index-1;j >= 0;j--){
			printf("%d%c",a[j],(j == 0 ? '\n' :' '));
		}
		memset(a,0,sizeof(a)/sizeof(a[0]));
		n = 0;
		index = 0;
	}
	return 0;	
}