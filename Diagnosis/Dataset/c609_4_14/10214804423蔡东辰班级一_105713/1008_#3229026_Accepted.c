#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char array[100];
	char* doc;
	double f;
	double* p_double;
	int integer;
	int* p_int;
	while(scanf("%s", array) != EOF){
		if((doc = strchr(array, '.')) != NULL){
			f = atof(array);
			p_double =  &f;
			int len = sizeof(double);
			int i = 0;
			unsigned char* p;
			for(p = (unsigned char*)p_double; i < len; i++){
				printf("%02x ", *(p+i));
			}
			printf("\n");
		}
		else{
			integer = atoi(array);
			p_int = &integer;
			int len_1 = sizeof(int);
			int i = 0;
			unsigned char* p;
			for(p = (unsigned char*)p_int; i < len_1; i++){
				printf("%02x ", *(p+i));
			}
			printf("\n");
		}
	}
	return 0;
}