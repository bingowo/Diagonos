#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	char num[400];
	unsigned char *p;
	int a;
	double b;
	int i;
	while(scanf("%s",num)!=EOF){
		if(strchr(num,'.')!=NULL){
			b=atof(num);
			p=(unsigned char*)&b;
			for(i=0;i<sizeof(double);i++){
				printf("%02x ",*(p+i));
			}
			printf("\n");
		}else{
			a=atoi(num);
			p=(unsigned char*)&a;
			for(i=0;i<sizeof(int);i++){
				printf("%02x ",*(p+i));
			}
			printf("\n");
		}
	}
} 