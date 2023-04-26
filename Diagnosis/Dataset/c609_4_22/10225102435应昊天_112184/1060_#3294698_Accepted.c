#include<string.h>
#include<stdio.h>
char* insert(char* s,int n);
int main(){
	char s[202],t[202];
	scanf("%s",s);
	strcpy(t,s);
	int len = strlen(s);
	int i = 0;
	for(i = 0;i < len;i++){
		if(strcmp(insert(strcpy(t,s),i),s) < 0){
			strcpy(s,t);
			i++;
			len++;
		}
	}
	printf("%s",s);
}
char* insert(char* s,int n){
	for(int i = strlen(s)+1;i > n;i--)
		s[i] = s[i-1];
	return s;
}