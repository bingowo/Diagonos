#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int cmp(const void* a,const void* b);
int main(){
	int T;
	scanf("%d",&T);
	getchar();
	char s[500];
	for(int i = 0;i < T;i++){
		char p[500][500];
		memset(p,'\0',sizeof(p));
		int cnt = 0;
		char* t = (char*)malloc(sizeof(char) * 500);
		memset(t,'\0',sizeof(t));
		int len = 0;
		char c;
		c = getchar();
		int flag = 0;                         //控制连续空格，标点情况 
		while(c != '\n'){
			if(c >= 'a' && c <= 'z'){
				t[len++] = c;
				flag = 0;
			}
			else if(!flag){
				t[len] = '\0';
				strcpy(p[cnt++],t);
				memset(t,'\0',sizeof(t));
				len = 0;
				flag = 1;	
			}
			c = getchar();
		}
		if(len != 0){
			t[len] = '\0';
			strcpy(p[cnt++],t);
		}
		qsort(p,cnt,sizeof(p[0]),cmp);
		printf("case #%d:\n",i);
		char* dif = (char*)malloc(sizeof(char)*500);
		strcpy(dif,p[0]);
		printf("%s ",dif);
		for(int k = 1;k < cnt;k++){
			if(strcmp(dif,p[k]) != 0)
				printf("%s ",p[k]);
			memset(dif,'\0',sizeof(dif));
			strcpy(dif,p[k]);
		}
		printf("\n");
		free(t);
		free(dif);
	}
} 
int cmp(const void* a,const void* b){
	return strcmp((char*)a,(char*)b);
}