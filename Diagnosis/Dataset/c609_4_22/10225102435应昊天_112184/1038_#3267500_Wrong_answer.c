#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
		int len = 0;
		int flag = 1;
		char c;
		c = getchar();
		while(c != '\n'){
			if(c >= 'a' && c <= 'z')
				t[len++] = c;
			else{
				t[len] = '\0';
				strcpy(p[cnt++],t);
				memset(t,'\0',sizeof(t));
				len = 0;	
			}
			c = getchar();
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