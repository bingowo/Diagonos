#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char hole[1001];
	while((scanf("%s",hole)) != EOF){
		char *p;
		if(strchr(hole,'.')){
			double a = atof(hole);
			double *pa = &a;
			unsigned char *ppa = (unsigned char*)pa;
			for(int i = 0;i<8;i++){
				printf("%02x ",*(ppa+i));
			}
			printf("\n");
		}
		else{
			int a = atoi(hole);
			int *pa = &a;
			unsigned  char *ppa = (unsigned char*)pa;
			for(int i = 0;i<4;i++)
				printf("%02x ",*(ppa+i));
			printf("\n");
		}
	}
} 