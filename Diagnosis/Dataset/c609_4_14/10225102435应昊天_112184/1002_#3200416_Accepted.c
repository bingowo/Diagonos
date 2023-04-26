#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
void itostr(int n,char*);
int longest_str(char* s);
int main(){
	int T;
	scanf("%d",&T);
	int a[10000];
	for(int i = 0;i < T;i++){
		scanf("%d",&a[i]);
	}
	for(int j = 0;j < T;j++){
		char* t = (char*)malloc(sizeof(char)*32); 
		itostr(a[j],t); 
		printf("case #%d:\n",j);
		printf("%d\n",longest_str(t));
		free(t);
	}
	return 0;
}

void itostr(int n,char* s){
	int i = 0;
	while(n > 0){
		s[i++] = n & 1?'1':'0';
		n >>= 1; 
	}
	s[i] = '\0';
}
int longest_str(char* s){
	int cnt = 1;
	int maxcnt = 1;
	char*p = s;
	for(int i = 0;i < strlen(s)-1;i++){
		if(s[i] == s[i+1] ){
			if(cnt > maxcnt)
				maxcnt = cnt;
			cnt = 1;
		}else{
			cnt++;
		}
		if(i+1 == strlen(s) - 1){
			if(cnt > maxcnt)
				maxcnt = cnt;
		}
			
	}
	return maxcnt;
}