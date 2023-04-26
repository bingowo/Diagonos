#include <stdio.h>

void NonRepBin(int);
int main(){
	int T, n;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		printf("case #%d\n",i);
		scanf("%d", &n);
		NonRepBin(n);
	}
	return 0;
}
void NonRepBin(int n){
	//将十进制数转为二进制表示
	int bin[40];
	int i = 0;
	printf("Reversed Binary:");
	while(n != 1){
		bin[i] = n % 2;
		n /= 2;
		i++;
		printf("%d",bin[i]);
	}
	
}