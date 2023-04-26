#include<string.h>
#include<stdio.h>
void insert(char* s,char c,int n);
int main(){
	char s[202];
	scanf("%s",s);
	int len = strlen(s);
	int i = 0;
	int flag = 0;   
	while(i < len){
		//printf("%d\n",i);
		if(s[i] < s[i+1]){
			if(flag){
				insert(s,s[i],i+1);
				insert(s,s[i],i+2);
				i += 3;
				len += 2;
				flag = 0;
			}else{
				insert(s,s[i],i+1);
				i += 2;
				len++;
			}
		}
		else if(s[i] == s[i+1]){
			flag = 1;
			i++;
		}
		else
			i++;
	}
	printf("%s",s);
}
void insert(char* s,char c,int n){
	for(int i = strlen(s)+1;i > n;i--){
		s[i] = s[i-1];
	}
	s[n] = c;
}