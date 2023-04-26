#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void solvedouble(double x){
	int c=sizeof(x);
	unsigned char* p=(unsigned char*)&x;
	while(c--) printf("%02x ",*p++);
}
void solveint(int x){
	int c=sizeof(x);
	unsigned char* p=(unsigned char*)&x;
	while(c--) printf("%02x ",*p++);
}
int main(){
	char s[1005];
	while(~scanf("%s",s)){
		if(strchr(s,'.')) solvedouble(atof(s));
		else solveint(atoi(s));
		puts("");
	}
	return 0;
}