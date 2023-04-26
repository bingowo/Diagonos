#include<stdio.h>
#include<string.h>
int num[20];
int copy[20];
int isPalindrome(int *s, int l){
	int i, flag = 1;
	for(i = 0; i < l / 2; ++i){
		if(s[i] != s[l-i-1]){
			flag = 0;
			break;
		}
	}
	return flag;
}
int main(){
	int n, i, len = 0, count = 0;
	scanf("%d", &n);
	while(n){
		num[len++] = n % 10;
		n = n / 10;
	}
	while(!isPalindrome(num, len)){
		count += 1;
		int temp = 0;
		for(i = 0; i < len; ++i)	copy[i] = num[i];
		for(i = 0; i < len; ++i){
			int x = (num[i] + copy[len-1-i]) / 10;
			num[i] = (num[i] + copy[len-1-i] + temp) % 10;
			temp = x;
		}
		if(temp != 0){
			num[len++] = temp;
		}
	}
	printf("%d ", count);
	for(i = len - 1; i >= 0; --i)	printf("%d", num[i]);
	return 0;
}