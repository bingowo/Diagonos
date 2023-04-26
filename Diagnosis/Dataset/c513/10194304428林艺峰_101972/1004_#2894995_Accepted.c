#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[110];
int main(){
	int i;
	while(scanf("%s", &str) != EOF){
		if(strchr(str, '.')){
			double x = atof(str);
			int l = sizeof(double);
			unsigned char *px = &x;
			for(i = 0; i < l; ++i){
				printf("%02x ", *(px+i));
			}
			printf("\n");
		}
		else{
			int x = atoi(str);
			int l = sizeof(int);
			unsigned char *px = &x;
			for(i = 0; i < l; ++i){
				printf("%02x ", *(px+i));
			}
			printf("\n");
		}
	}
	return 0;
}