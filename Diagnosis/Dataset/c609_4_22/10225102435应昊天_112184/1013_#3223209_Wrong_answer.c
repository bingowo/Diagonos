#include<stdio.h>
#include<string.h>
long long  int_pow(int base,int exp);
int main(){
	char s[10000];
	unsigned long long n = 0;              //转换后的二进制 
	int cnt = 0;                  //总位数                
	int base = 1;                 //二进制位的值 
	int exp;
	long long a = 0,b = 0;
	scanf("%s",s);
	for(int i = 2;i < strlen(s);i++){
		if(s[i]>='A' && s[i] <= 'Z')
			n = n * 16 + s[i] - 'A' + 10;
		else
			n = n * 16 + s[i] - '0';
	}
	printf("%llu\n",n);
	while(n > 0){
		exp = int_pow(-4,cnt/4);
		base = n & 1;
		switch(cnt % 4){
			case 0:
				a += base * exp;
				break;
			case 1:
				a -= base * exp;
				b += base * exp;
				break;
			case 2:
				b += -2 * base * exp;
				break;
			case 3:
				a += 2 * base * exp;
				b += 2 * base * exp;
				break;
		}
		cnt++;
		n >>= 1;	
	}
	if(a == 0){
		if(b == 0)
			printf("%lld",0);
		else if(b == 1)
			printf("i");
		else if(b == -1)
			printf("-i");
		else
			printf("%lldi",b);
	}else{
		if(b == 0)
			printf("%lld",a);
		else if(b == 1)
			printf("%lld+i",a);
		else if(b == -1)
			printf("%lld-i",a);
		else if(b < 0)
			printf("%lld%lldi",a,b);
		else
			printf("%lld+%lldi",a,b);
	}
	return 0;
}
long long int_pow(int base,int exp){
	long long ans = 1;
	for(int i = 0;i < exp;i++){
		ans *= base;
	} 
	return ans;
}