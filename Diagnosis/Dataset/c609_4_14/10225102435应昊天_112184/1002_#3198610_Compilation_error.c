#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int main(){
	int T;
	scanf("%d",&T);
	int a[10000];
	for(int i = 0;i < T;i++){
		scanf("%d",&a[i]);
	}
	int i = 0;
	char c;
	int cnt = 0;
	int len = 0;
	int maxcnt = 0;
	char* p;
	for(int j = 0;j < T;j++){
		char* s = (char*)malloc(sizeof(char)*32);
		while(a[j] > 0){
			s[i++] = a[j] & 1;
			a[j] >>= 1; 
		}
		s[i] = '\0';
		len = strlen(s);
		int b[strlen(s)] = {0};
		for(int k = strlen(s) - 1;k > 0;k--){
			char* t = (char*)malloc(sizeof(char)*32);
			c = s[k];
			s[k] = '0';
			strcpy(t,s);
			s[k] = c;
			while(strlen(s) > strlen(t)){
				if((p = strstr(s,t)) != NULL){
					b[strlen(t)]++;
					s += strlen(t);
				}
				else
					break;
			}
		}
		for(int r = 0;r < strlen(s);r++){
			if(b[r] > maxcnt)
				maxcnt = b[r];
		}
		printf("case #%d:\n",j);
		printf("%d\n",maxcnt);
	}
	return 0;
}