#include <stdio.h>
void d2i(int, int);

int main(){
	int T; //数据组数 
	scanf("%d", &T);
	int N, R;
	for(int i = 0; i < T; i++){
		scanf("%d %d", N, R);
		d2i(N, R);	
	}
	return 0;
}

void d2i(int N, int R){
	const char mod[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	int sgn = N >=0 ? 1:-1;
	N *= sgn;
	char ans[100] = {0};
	int i;
	if(sgn == -1){
		ans[0] = '-';
		i = 1;
		while(N){
			ans[i] = N % R;
			N /= R; 
			i++;
		}
	}else{
		i = 0;
		while(N){
			ans[i] = N % R;
			N /= R; 
			i++;
		}
	}
	for(int j = 0 ; j < i; j++){
		printf("%s",ans);
	}
	printf("%s",'\n');
}