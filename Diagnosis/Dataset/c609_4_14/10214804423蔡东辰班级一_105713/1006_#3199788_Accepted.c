#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long MAXNUM = 1000000000000000000;
static long long powL(char number[], int table[], int i, int x);
int main(){
	int T, len;//len记录每次输入的字符串长度
	scanf("%d", &T);
	for(int i = 0; i<T; i++){
		int cnt = 2;//记录一共有多少的字符
		char* msg = (char*)malloc(sizeof(char)*61);
		scanf("%s", msg);
		int table[123];
		for(int i = 0; i<123; i++){
			table[i] = -1;
		}
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
			else if(table[msg[j]] == -1 && zero==1){
				table[msg[j]] = 0;
				zero = 0;
			}
			else if(table[msg[j]] == -1 && zero==0){
				table[msg[j]] = cnt++;
			}
		}
		printf("case #%d:\n", i);
		long long result = powL(msg, table, len-1, cnt);
		printf("%lld\n", (result > MAXNUM)? MAXNUM : result);
		free(msg);
	}
	
	return 0;
}
static long long powL(char number[], int table[], int i, int x){
	if(i==0){
		return table[number[0]];
	}
	return table[number[i]] + x * powL(number, table, i-1, x);
}