#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char s[31];
	int n;
	double m;
	while(scanf("%s",s) != EOF){
		if(strchr(s,'.') == NULL){
			n = atoi(s);
			unsigned char* p = (unsigned char*)&n;
			int c = sizeof(n);
			while(c--){
				printf("%02x ",*p++);
			}
			printf("\n");
		}else{
			m = atof(s);
			unsigned char* p = (unsigned char*)&m;
			int c = sizeof(m);
			while(c--){
				printf("%02x ",*p++);
			}
			printf("\n");
		}
	}
	return 0;
} 