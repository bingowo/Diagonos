#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct data {
	char m[101];
};

int main(int argc, char *argv[]) {
	int T;
	scanf("%d",&T);
	getchar();
	int t, length,numOfWord;
	for (t = 0; t < T; t++){
		//输入以及初始化 
		char *s;
		struct data d[100];
		s = (char *)malloc(sizeof(char)*100);
		gets(s); 
		char *p = s;
		numOfWord = 0;
		
		//代码部分-分开单词
		//单词存放在结构体数组地下的char型数组里了 
		while (*p != '\0'){
			char *p2;
			if (isspace(*p) != 0){
				p++;
			}else{
				p2 = p + 1;
				while (*p2 != '\0' && isspace(*p2) == 0){
					if(*p2 > 'A' && *p2 < 'Z'){
						*p2 = *p2 - 32;
					} 
					p2++;
				}
				length = p2 - p;
				strncpy(d[numOfWord].m,p,length); 
				p = p2;
				d[numOfWord].m[length] = '\0';
				numOfWord++; 
			}
		}
		
		
		//代码部分-去掉the，a，an，of，for, and
		int i;
		for (i = 0; i < numOfWord; i++){
			if ((strcmp(d[i].m,"the") == 0 && strlen(d[i].m) == 3) ||
				(strcmp(d[i].m,"a") == 0 && strlen(d[i].m) == 1)||
				(strcmp(d[i].m,"an") == 0 && strlen(d[i].m) == 2)||
				(strcmp(d[i].m,"of") == 0 && strlen(d[i].m) == 2)||
				(strcmp(d[i].m,"for") == 0 && strlen(d[i].m) == 3)||
				(strcmp(d[i].m,"and") == 0 && strlen(d[i].m) == 3)||
			){
				numOfWord--;
			}
			//没有考虑到大小写
			 
		}
		//输出 
		printf("case #%d:\n%d\n",t,numOfWord);
		free(s);
	} 
	return 0;
}