#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void solveint(int n){
	int c=sizeof(int);
	unsigned char* p=(unsigned char*)&n;
	while (c--) printf("%02x ",*p++);
	printf("\n");
}

void solvedouble(double m){
	int c=sizeof(double);
	unsigned char* p=(unsigned char*)&m;
	while(c--) printf("%02x ",*p++);
	printf("\n");
}

int main(){
	char s[31];
	while(scanf("%s",s)!=EOF){
		if (strchr(s,'.')) solvedouble(atof(s));
		else solveint(atoi(s));
	}
	return 0;
}