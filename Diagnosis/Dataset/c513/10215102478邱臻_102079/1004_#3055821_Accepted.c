#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    char n[10000];
    double a;
    int b;
    double *p1;
    int *p2;
    unsigned char* p;
    while((scanf("%s",n))!=EOF){
    	if(strchr(n,'.')!=NULL){
    		a=atof(n);
    		p1=&a;p=(unsigned char*)p1;
    		printf("%02x %02x %02x %02x %02x %02x %02x %02x\n",*p,*(p+1),*(p+2),*(p+3),*(p+4),*(p+5),*(p+6),*(p+7));
		}
		else {
			b=atoi(n);
			p2=&b;p=(unsigned char*)p2;
			printf("%02x %02x %02x %02x\n",*p,*(p+1),*(p+2),*(p+3));
		}
	}
	return 0;
}
