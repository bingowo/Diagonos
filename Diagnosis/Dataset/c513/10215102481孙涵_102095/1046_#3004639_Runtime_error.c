#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct data {
	char m[101];
};

int main(int argc, char *argv[]) {
	int T;
	scanf("%d",&T);
	getchar();
	int t, length,numOfWord;
	char *p2;
	char *s;
	char *p;
	for (t = 0; t < T; t++){
		//输入以及初始化 
		struct data d[100];
		s = (char *)malloc(1000);
		gets(s); 
		p = s;
		numOfWord = 0;
		
		//代码部分-分开单词
		//单词存放在结构体数组地下的char型数组里了 
		while (*p != '\0'){
			if (isspace(*p) != 0){
				p++;
			}else{
				p2 = p;
				while (*p2 != '\0' && isspace(*p2) == 0){
					p2++;
				}
				length = p2 - p;
			}
			strncpy(d[numOfWord].m,p,length); 
			numOfWord++; 
		}
		
		//代码部分-去掉the，a，an，of，for, and
		int i;
		for (i = 0; i < numOfWord; i++){
			if (strcmp(d[i].m,"the") == 0 ||
				strcmp(d[i].m,"a") == 0 ||
				strcmp(d[i].m,"an") == 0 ||
				strcmp(d[i].m,"of") == 0 ||
				strcmp(d[i].m,"for") == 0 ||
				strcmp(d[i].m,"and") == 0
			){
				numOfWord--;
			}
		}
		//输出 
		printf("case #%d:\n%d\n",t,numOfWord);
		free(s);
	} 
	return 0;
}