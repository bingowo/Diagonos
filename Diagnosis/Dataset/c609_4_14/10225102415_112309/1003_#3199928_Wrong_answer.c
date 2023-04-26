#include <stdio.h>

void Bilibili(unsigned long long);
int main(){
	int T;
	unsigned long long n;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		scanf("%llu", &n);
		Bilibili(n);
	}
	return 0;
}
void Bilibili(unsigned long long n){
	unsigned long long ret[10000] = {0};
	int i = 0;
	while(n){
		ret[i] = n % 2333;
		n /= 2333;
		i++;
	}
	if(n != 0){
		for(--i; i > 0; i--){
			printf("%llu ",ret[i]);
		}
	}
	printf("%llu",ret[0]);
	printf("\n");
}