#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char s[100001];
unsigned int a[3000];
unsigned int f(char c){
	int i;
	char s1[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e'};
	for(i = 0; i < 15; i++){
		if(c == s1[i])return i;
	} 
	return -1;
}
int main(){
	int i, n, k = 0, j, num = 0;
	unsigned int sum = 0;
	char c[] = "0x";
	scanf("%s", &s);
	for(i = 0; i < strlen(s); i++){
		if(s[i] == '0' && s[i+1] == 'x')a[num++] = i;
		}
		//printf("%d\n", num);
	if(num == 0)printf("-1");
	else if(num == 1){
		for(i = 2; i < strlen(s); i++){
			if(f(s[i]) == -1)break;
			else sum = sum*16 + f(s[i]);
		}
		if(sum != 0)printf("%u", sum);
		else printf("-1");
		sum = 0;
	}
	else {
		for(j = 1; j < num; j++){
			for(k = a[j-1]+2; k < a[j]; k++){
				if(f(s[k]) == -1)break;
				else sum = sum*16 + f(s[k]);
			}
			if(sum != 0)printf("%u ", sum);
			sum = 0;
		}
		for(i = a[j-1]+2; i < strlen(s); i++){
			if(f(s[i]) == -1)break;
			else sum = sum*16 + f(s[i]);
		}
		if(sum != 0)printf("%u", sum);
		sum = 0;
	}
	
	return 0;
} 