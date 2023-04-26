#include<stdio.h>
#include<string.h>
typedef union{
    int i;
    double f;
}NUM;

int main(void)
{
	char a[1000];
    NUM input;
    while(scanf("%s",a) != EOF){
    	char *find = a;
    	
    	if(strchr(a,'.') == NULL){//if int
    		while(*find != '\0') find++;
    		for(find--;find - a >= 0;find--) ungetc(*find,stdin);
    		scanf("%d",&input.i);
    		int size_int = sizeof(int);
    		for(;size_int > 0;size_int -= 1){
        		printf("%02x ",0xFF & (input.i >> (size_int*8-8)));
			}
			putchar('\n');
		}
		
		else{
			while(*find != '\0') find++;
    		for(find--;find - a >= 0;find--) ungetc(*find,stdin);
    		scanf("%lf",&input.f);
    		int size_double = sizeof(double);
    		unsigned char *out = (unsigned char *)&input.f;
        	for(;size_double > 0;size_double -= 1){
        		printf("%02x ",*out);
        		out++;
			}
			putchar('\n');
		}
	}
    return 0;
}