#include<stdio.h>
#include<stdlib.h>
char num[1100];
int main(){
	int n, r, temp, len = 0, i;
	scanf("%d%d", &n, &r);
	while(n){
		temp = n % r;
		n = n / r;
		if(temp < 0){
			temp -= r;
			n += 1;
		}
		if(temp >= 10){
			num[len++] = temp - 10 + 'A';
		}
		else{
			num[len++] = temp + '0';
		}
	}
	if(len == 0)	printf("0");
	else	for(i = len - 1; i >= 0; --i){	printf("%c", num[i]);}
	return 0;
}