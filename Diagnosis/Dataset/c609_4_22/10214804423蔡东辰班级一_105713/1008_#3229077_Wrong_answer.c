#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char array[100];
	char* doc;
	int len;
	double* p_double;
	int* p_int;
	unsigned char* p;
	while(scanf("%s", array) != EOF){
		if((doc = strchr(array, '.')) != NULL){
			double f = atof(array);
			p_double =  &f;
			len = sizeof(double);
			p = (unsigned char*)p_double;
		}
		else{
			int integer = atoi(array);
			p_int = &integer;
			len = sizeof(integer);
			p = (unsigned char*)p_int;
		}
		for(int i = 0; i < len; i++){
			printf("%02x ", *(p+i));
		}
		printf("\n");
	}
	return 0;
}