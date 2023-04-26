#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char array[100];
	char* doc;
	int len, integer;
	double f;
	double* p_double;
	int* p_int;
	unsigned char* p;
	while(scanf("%s", array) != EOF){
		if((doc = strchr(array, '.')) != NULL){
			f = atof(array);
			p_double =  &f;
			len = sizeof(double);
			p = (unsigned char*)p_double;
		}
		else{
			integer = atoi(array);
			p_int = &integer;
			len = sizeof(int);
			p = (unsigned char*)p_int;
		}
		for(int i = 0; i < len; i++){
			printf("%02x ", *(p+i));
		}
		printf("\n");
	}
	return 0;
}