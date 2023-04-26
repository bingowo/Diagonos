#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char num[10000];
	char c;
	double a;
	int b;
	double* p1;
	int* p2;
	unsigned char* p;
	while((c=getchar())!=EOF){
		scanf("%s",num);
		if(strchr(num,'.')!=NULL){
			a=atof(num);
			p1=&a;
			p=(unsigned char*)p1;
			printf("%02x %02x %02x %02x %02x %02x %02x %02x\n",p,p+1,p+2,p+3,p+4,p+5,p+6,p+7);
		}
		else {
			b=atoi(num);
			p2=&b;
			(unsigned char*)p2;
			printf("%02x %02x %02x %02x\n",p,p+1,p+2,p+3);
		}
	}
	return 0;
}