#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void Cdouble(double x){
	int c=sizeof(double);
	unsigned char*p =(unsigned char*)(&x);//为了输出每个字节的数据，一个char，一个字节 
	while(c--){
		printf("%02x ",*p++);
	}
}
void Cint(int x){
	int c=sizeof(int);
	unsigned char*p =(unsigned char*)(&x);//为了输出每个字节的数据，一个char，一个字节 
	while(c--){
		printf("%02x ",*p++);
	}
}
int main()
{ char s[1000];
	while(scanf("%s",s)!=EOF){
		if(strchr(s,'.')==0) Cint(atoi(s));
		else Cdouble(atof(s));
		}
	

 return 0;
}