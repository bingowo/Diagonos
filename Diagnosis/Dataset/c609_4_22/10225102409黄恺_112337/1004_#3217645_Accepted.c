#include <stdio.h>
#include <string.h>

void NtoR(long long N, int R) {		//自定义十进制转R进制函数 
	char num[100] = {0};
	int n = 0;
	while (N > 0) {
		int number = N % R;
		if (number > 9) {
			number = number - 10 +'A';
		} else {
			number = number + 48;
		}
		num[n] = number;
		N = N / R;
		n++;
	}

	for (n--; n >= 0; n--) {
		printf("%c", num[n]);
	}
	printf("\n");
}

int HtoD(char digit) {		//自定义字母转数字函数  
	int ans;
	if (digit >= 'A' && digit <= 'Z') {
		ans = digit - 'A' + 10;
	} else if (digit >= 'a' && digit <= 'z') {
		ans = digit - 'a' + 10;
	} else {
		ans = digit - '0';
	}
	return ans;
}

int main() {
	int A, B;
	char n[106];
	scanf("%d %s %d", &A, n, &B);
	if (!strcmp(n, "0")) {
		printf("0");
	}  else {
		int len = strlen(n);
		int N = 0;		//总和 
		int weight = 1;		//权重 
		while(len--) {
			N += HtoD(n[len])*weight;
			weight*=A;
		}
		NtoR(N, B);		
	}

	

	return 0;
} 