#include<string.h>
#include<stdio.h>
void insert(char* s,char c,int n);
int main(){
	char s[101];
	scanf("%s",s);
	int len = strlen(s);
	int i = 0;
	while(i < len){
		if(s[i] < s[i+1]){
			insert(s,s[i],i+1);
			i += 2;
			len++;
		}
		else if(s[i] >= s[i+1]){
			i++;
		}
	}
	printf("%s",s);
}
void insert(char* s,char c,int n){
	for(int i = strlen(s)+1;i > n;i--){
		s[i] = s[i-1];
	}
	s[n] = c;
}