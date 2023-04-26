#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int x;
	char s[100];
	unsigned char* t; 
	int i;int a;double b;
	while((scanf("%s" ,s))!=EOF){
		if((strchr(s,'.'))==NULL){
			a = atoi(s);
			x =sizeof(a);
			int* b=&a;
			t=(unsigned char*)b;
		}else{
			b =atof(s);
			x= sizeof(b);
			double* c=&b;
			t=(unsigned char*)c;
		}
		for(i=0;i<x;i++){
			printf("%02x ",*t++) ;
			
		}
		printf("\n");
	}
	return 0;
} 

