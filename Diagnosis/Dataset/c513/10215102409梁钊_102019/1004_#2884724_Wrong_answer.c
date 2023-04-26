#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s[100] ;
	while(scanf("%s",&s)!=EOF){
		if(strchr(s,'.')){
			double n = atof(s);
			double* _p = &n ;
			unsigned char* p = (unsigned char*) _p ;
			for(int i=0;i<sizeof(double);i++) 
				printf("%02x ",*p++) ;
		}
		else{
			int n = atoi(s);
			int* _p = &n ;
			unsigned char* p = (unsigned char*) _p ;
			for(int i=0;i<sizeof(int);i++)
				printf("%02x ",*p++) ;
		}
		printf("");
	}
}