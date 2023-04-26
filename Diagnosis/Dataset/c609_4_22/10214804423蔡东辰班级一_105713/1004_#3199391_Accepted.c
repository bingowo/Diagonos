#include <stdio.h>
#include <string.h>
static unsigned powL(char number[], int i, int x);
void DtoR(unsigned n, int R);
int main(){
	int A, B;
	unsigned n = 0;
	char number[32];
	scanf("%d %s %d", &A, number, &B);
	int len = strlen(number);
	n = powL(number, len - 1, A);//将A进制转化为十进制
	if(n==0){
		printf("0 ");
	}
	else{
		DtoR(n, B);
	}
	return 0;
}
static unsigned powL(char number[], int i, int x){
	if(i==0){
		return (number[i]>='a')? (number[i]-'a'+10): (number[i]>='A')?number[i]-'A'+10:number[i]-'0';
	}
	unsigned bit = (number[i]>='a')? (number[i]-'a'+10): (number[i]>='A')?number[i]-'A'+10:number[i]-'0';
	return bit + x * powL(number, i-1, x);
}
void DtoR(unsigned n, int R){
	if(n==0){
		return;
	}
	int r = n % R;
	DtoR(n/R, R);
	if(r>9){
		printf("%c", 'A'+r-10);
	}
	else{
		printf("%c", '0' + r);
	}
}