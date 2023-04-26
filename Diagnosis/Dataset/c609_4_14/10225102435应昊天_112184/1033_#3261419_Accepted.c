	#include<stdio.h>
	#include<string.h>
	static char tab[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int main(){
		int T;
		scanf("%d",&T); 
		char s[100];
		for(int i = 0;i < T;i++){
			scanf("%s",s);
			char t[(strlen(s)+1) * 8 ]; 
			int cnt = 0;
			for(int j = 0;s[j] != '\0';j++){
				int temp = s[j];
				for(int k = 7;k >= 0;k--){
					t[cnt++] = temp>>k & 1 ? '1' : '0';
				}
			}
			while((cnt) % 6){
				t[cnt++] = '0';
			}
			t[cnt] = '\0';
			printf("case #%d:\n",i);
			for(int q = 0;q < cnt / 6;q++){
				int sum = 0;
				for(int p = q * 6;p - q * 6 < 6;p++){
					sum = sum * 2 + t[p] - '0'; 
				}
				putchar(tab[sum]);
			}
			int len = (cnt + 1) / 6;
			while(len % 4 != 0){
				putchar('=');
				len++;
			}
			printf("\n");
		}
		return 0;
	} 