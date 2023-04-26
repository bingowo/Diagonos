#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 25

void combination_op(char* pstr, char* output, int m);
void combination(char* pstr);


int main(){
//	char* pstr = "";
	char pstr[MAX] = "";
//	FILE *fp = fopen("input.txt", "r");

	printf("输入待处理的字符串:\n");
	while(gets(pstr) != NULL);

	combination(pstr);

/*	if(fp != NULL){
		while(fgets(pstr, sizeof(pstr), fp) != NULL);
		combination(pstr);
	}
*/
	return EXIT_SUCCESS;
}

void combination(char* pstr){
	int cap;

	if(pstr == NULL){
		printf("空串！\n");
		return;
	}
	for(cap = 1; cap <= (int)strlen(pstr); cap++){
		char output[MAX] = "";
		combination_op(pstr, output, cap);
	}
}
void combination_op(char* pstr, char* output, int m){
	/*
	**当剩下的字符恰好够组合时，直接全部复制到输出字串中。
	*/
	if((int)strlen(pstr) == m){
		strcat(output, pstr);
		printf("%s\n",output);
		*(output + (int)strlen(output) - m - 1) = '\0';//回溯
		return;
	}
	/*
	**输出串已满时
	*/
	if(m <= 0){
		printf("%s\n", output);	
		*(output + (int)strlen(output) - 1) = '\0';//回溯
	}else{
		//添加当前字符
		strncat(output, pstr,1);
		combination_op(pstr+1, output, m-1);
		//不添加当前字符
		combination_op(pstr+1, output, m);
	}
}
