#include <stdio.h>
int main(){
	int T;
	long long N, R;
	char str[50];
	int negative = 0;
	scanf("%d", &T);
	for(int i = 0; i<T; i++){
		int cnt = 0;
		scanf("%lld %lld", &N, &R);
		int negative = (N<0)?1:0;
		if(N==0){
			printf("0\n");
			continue;
		}
		while(N>0){
			if(N%R<10){
				printf("N %d\n", N);
				str[cnt++] = '0' + (N%R);
				N /= R;
			}
			else{
				str[cnt++] = 'A' + (N%R) - 10;
				N /= R;
			}
		}
		if(negative){
			N = -N;
			while(N>0){
			if(N%R<10){
				str[cnt++] = '0' + (N%R);
				N /= R;
			}
			else{
				str[cnt++] = 'A' + (N%R) - 10;
				N /= R;
			}
		}
		}
		if(negative){
			str[cnt++] = '-';//先加
		}
		for(int j = cnt-1; j>=0; j--){//后减
			printf("%c", str[j]);
		}
		printf("\n");
	}
	return 0;
	
}