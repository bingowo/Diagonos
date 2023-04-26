#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char in[1000];
	while((scanf("%s",in))!=EOF){
			char *p;
	if((p=strchr(in,'.'))!=NULL){
		double a=atof(in);
		double *pa=&a;
		(unsigned char*)pa;
		for(int i=0;i<8;i++)
		printf("%02x ",*(pa++));
		printf("\n");
	}else{
		int a=atoi(in);
		int *pa=&a;
		(unsigned char*)pa;
		for(int i=0;i<4;i++)
		printf("%02x ",*(pa++));
		printf("\n");	
	}
}
	return 0;
}