#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void char2Binary(char* B, char c, int index){
	int i;
	int n = (int)c;
	for(i = 7, index; i>=0; i--, index++){
		if((n>>i) & 1){
			B[index] = '1';
		}
		else{
			B[index] = '0';
		}
	}
}
static int Horner(char* T, int index){
	if(index % 6 == 0){
		return T[index] - '0';
	}
	int result = T[index] - '0';
	return result + 2 * Horner(T, index-1);
}
int main(){
	char table[64];
	for(int i = 0; i<26; i++) table[i] = 'A' + i;
	for(int i = 0; i<26; i++) table[26+i] = 'a' + i;
	for(int i = 0; i<10; i++) table[52+i] = '0' + i;
	table[62] = '+'; table[63] = '/';
	int T;
	scanf("%d", &T);
	for(int i = 0; i<T; i++){
		char input[101] = {0};
		scanf("%s", input);
		int len = strlen(input);//输入长度
		char transformer[8*len+7];
		for(int j = 0; j<len; j++){//遍历input，把每个字符录入transformer
			char2Binary(transformer, input[j], 8*j);
		}
		transformer[8*len] = '\0';//处理末尾
		int Blen = strlen(transformer);//最初的二进制长度
		if(Blen%6){
			for(int j = Blen; j<Blen + 6 - Blen%6; j++){
				transformer[j] = '0';
			}
			transformer[Blen + 6 - Blen%6] = '\0';
		}//不够补零
		Blen = strlen(transformer);//更新后长度
		char result[100];
		int k = 0;
		for(int j = 5; j<Blen; k++, j += 6){
			int d = Horner(transformer, j);
			result[k] = table[d];
		}
		result[k] = '\0';//补零
		printf("case #%d:\n%s", i, result);
		int rlen = strlen(result);
		while(rlen % 4){
			printf("=");
			rlen++;
		}
		printf("\n");
	}
	return 0;
}