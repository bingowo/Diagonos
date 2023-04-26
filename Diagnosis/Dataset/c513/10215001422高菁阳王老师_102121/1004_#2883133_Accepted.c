#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void solveint(int n){
	int c;
	unsigned char *p=(unsigned char *)&n;
	c=sizeof(n);
	while (c--)
		printf("%02x ", *p++);
		 printf("\n");
	}
void solvedouble(double n){
	int c;
	unsigned char *p=(unsigned char *)&n;
	c=sizeof(n);
	    while (c--)
        printf("%02x ", *p++);
    printf("\n");

}

int main(int argc, char *argv[]) {
	char s[100];
	while(scanf("%s",s)!=EOF)
	if(strchr(s,'.')==0)
	            solveint(atoi(s));
        else 
            solvedouble(atof(s));

	return 0;
}