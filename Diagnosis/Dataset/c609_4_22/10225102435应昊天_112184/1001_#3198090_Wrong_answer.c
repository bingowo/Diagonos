#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reverse(char* s);
int main(){
	int T;
	scanf("%d",&T);
	int a[10000][2];
	for(int i = 0;i < T;i++){
		scanf("%d %d",&a[i][0],&a[i][1]);
	}
	int k = 0; 
	int flag = 0;
	for(int j = 0;j < T;j++){
		char* s = (char*)malloc(sizeof(char)*32);
		if(a[j][0] < 0){
				flag = 1;
				a[j][0] *= -1; 
		}
		while(a[j][0] > 0){
			if(a[j][0] % a[j][1] < 10){
				s[k++] = a[j][0] % a[j][1] + '0';
			}
			else{
				s[k++] = a[j][0] % a[j][1] - 10 + 'A';
			}
			a[j][0] /= a[j][1];
		}
		if(flag)
			s[k++] = '-';
		s[k] = '\0';
		reverse(s);
		printf("%s\n",s);
		k = 0;
	}
	return 0;
} 
void reverse(char* s){
	char temp;
	for(int i = 0;i < strlen(s) / 2;i++){
		s[i] = s[strlen(s) - i - 1];
		temp = s[strlen(s) - i - 1];
		s[i]= temp;
	}
}