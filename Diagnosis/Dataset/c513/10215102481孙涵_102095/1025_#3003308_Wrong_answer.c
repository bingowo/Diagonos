#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct data{
	int u;
	char word[100];
};

typedef struct data S;

int countAlpha(char *word);
int cmp(const void*a, const void*b);

int main(int argc, char *argv[]) {
	int T;
	scanf("%d",&T);
	int i;
	for (i = 0; i < T; i++){
		S s[100]; 
		int n;
		scanf("%d",&n);
		int j;
		for (j = 0; j < n; j++){
			scanf("%s", s[j].word);
			//计算有多少个不同的字符
			 s[j].u = countAlpha(s[j].word);
		} 
		qsort(s,n,sizeof(S),cmp);
		printf("case #%d:\n", i);
		for (j = 0; j < n; j++){
			printf("%s\n",s[j].word);
		}
	} 
	return 0;
}

int countAlpha(char *word){
	int allchar[256] = {0};
	int i, j, alpha = 0;
	j = strlen(word);
	for (i = 0; i < j; i++){
		if (allchar[word[i]] != 0){
			allchar[word[i]] = 1;
			alpha++;
		}
	}
	return alpha;
} 

int cmp(const void*a, const void*b){
	S s1 = (*(S *)a);
	S s2 = (*(S *)b);
	if (s1.u == s2.u){
		return strcmp(s1.word,s2.word);
	}else{
		return s2.u - s1.u;
	}
}