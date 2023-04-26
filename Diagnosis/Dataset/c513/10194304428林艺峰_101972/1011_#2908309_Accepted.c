#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
char str[110];
int num[220];
int main(){
	scanf("%s", &str);
	int l = strlen(str), i, x, len = 0;
	long long real = 0, imaginary = 0, real_1 = 0, imaginary_1 = 0;
	for(i = 2; i < l; ++i){
		if(str[i] >= 'A' && str[i] <= 'Z')	x = str[i] - 'A' + 10;
		else	x = str[i] - '0';
		len = 0;
		while(x){
			num[(i-1)*4-1-len] = x % 2;
			x = x / 2;
			len++;
		}
	}
	for(i = 0; i < (l - 2) * 4; ++i){
		real_1 = 0 - real - imaginary + num[i];
		imaginary_1 = real - imaginary;
		real = real_1;
		imaginary = imaginary_1; 
	}
	if(real == 0 && imaginary == 0)	printf("0");
	else if(real == 0){
		if(imaginary == 1)	printf("i");
		else if(imaginary == -1)	printf("-i");
		else	printf("%lldi", imaginary);
	}
	else{
		if(imaginary == 0)	printf("%lld", real);
		else if(imaginary == 1)	printf("%lld+i", real);
		else if(imaginary == -1)	printf("%lld-i", real);
		else if(imaginary > 0)	printf("%lld+%lldi", real, imaginary);
		else	printf("%lld%lldi", real, imaginary);
	}
	return 0;
}