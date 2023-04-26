#include <stdio.h>
#include <string.h>
static unsigned powL(char number[], char table[], int i, int x);
int main(){
	char msg[61];
	char table[123] = {-1};
	for(int i = 0; i<123; i++){
		table[i] = -1;
	}
	int T, len;//len记录每次输入的字符串长度
	scanf("%d", &T);
	for(int i = 0; i<T; i++){
		int cnt = 2;//记录一共有多少的字符
		scanf("%s", msg);
		if((len = strlen(msg)) ==1 ){//若长度为 1
			printf("case #%d:\n1\n", i);
			continue;
		}
		//长度大于一，前两种的数码一定是固定的。
		table[msg[0]] = 1;
		int zero = 1;//标记0码
		for(int j = 1; j<len; j++){
			if(table[msg[j]] != -1){
				continue;
			}
			else if(table[msg[j]] == -1 && zero){
				table[msg[j]] = 0;
				zero = 0;
			}
			else if(table[msg[j]] == -1 && zero==0){
				table[msg[j]] = cnt++;
			}
		}
//		printf("%d进制\n", cnt);
		printf("case #%d:\n%d\n", i, powL(msg, table, len-1, cnt));
	}
	
	return 0;
}
static unsigned powL(char number[], char table[], int i, int x){
	if(i==0){
		return table[number[0]];
	}
	return table[number[i]] + x * powL(number, table, i-1, x);
}