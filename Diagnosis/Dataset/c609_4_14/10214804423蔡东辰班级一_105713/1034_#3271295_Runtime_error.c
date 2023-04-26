#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned int c2h(char* s, int len, int* table){
	if(len == 0){
		return table[*(s+len)];
	}
	return table[*(s+len)] + 16*c2h(s, len-1, table);
}
int main(){
	//映射表
	int table[128] = {0};//检查是否合法
	int caltable[128] = {0};//参与进制转换
	for(char c = '0'; c<='9'; c++){table[c] = 1; caltable[c] = c - '0';}
	for(char c = 'a'; c<='f'; c++){table[c] = 1; caltable[c] = c - 'a' + 10;}
	char str[100001] = {0};
	scanf("%s", str);
	char* ptr;
	ptr = strstr(str, "0x");
	if(ptr == NULL){
		printf("-1");
	}
	else{
	int len = 0;
	int no = 1;
	while((ptr = strstr(str+len, "0x")) != NULL){
		if(table[*(ptr+2)] == 0){
			len = (ptr - str)/sizeof(char) + 2;
			continue;
		}
		int cnt = 0;
		int m = 2;
		while(*(ptr+m) == '0'){
			m++;
		}
		unsigned int result;
		while (table[*(ptr+cnt+m)]){
			cnt++;
		}
		int legth = (cnt>8)?8:cnt;
		result = c2h(ptr+m, legth-1, caltable);
		printf("%d ", result);
		no = 0;
		len = (ptr - str)/sizeof(char) + cnt+2;
	}
	if(no){
		printf("-1");
	}
	}
	return 0;
}